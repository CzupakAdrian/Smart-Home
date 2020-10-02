#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NetworkInterfaces.hpp"
#include "Device.hpp"
#include "DevicesContainer.hpp"
#include "DevicesManager.hpp"
#include "AppInterfaces.hpp"
#include "BasicDefinitions.hpp"
#include "Directory.hpp"
#include <memory>
#include <algorithm>

using namespace SmartHome;


struct NetworkClientSenderMock : public NetworkClientSender
{
    MOCK_METHOD(void, send, (Message), (override));
};

struct DevicesManagerFixture : public testing::Test
{
    testing::StrictMock< NetworkClientSenderMock > sender;
    DevicesManager manager{sender};
    DevicesAccesor & accesor = manager;
    DevicesAdder & adder = manager;
    
    bool changeName(Device device, Name name)
    {
        return accesor.tryToChangeName(device, name);
    }

    bool exists(std::set< Device > list, Device device)
    {
        return std::find(list.begin(), list.end(), device)
            != list.end();
    }
};

struct DevicesManagerWithTwoDevicesFixture : public DevicesManagerFixture
{
    Device device1{"name1", "type1"};
    Device device2{"name2", "type2"};
};

TEST(InitialTests, shouldPass)
{
    ASSERT_TRUE(true);
}

TEST(DeviceTest, equalComparisonWorks)
{
    const Name name{"name"};
    const DeviceType type{"type"};
    Device dev1{name, type}, dev2{name, type};
    ASSERT_TRUE(dev1 == dev2);
}

TEST_F(DevicesManagerWithTwoDevicesFixture, changingNameToTheSameReturnsFalse)
{
    ASSERT_FALSE(changeName(device1, device1.name));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, changingNameToNonExistingOneReturnsTrue)
{
    ASSERT_TRUE(changeName(device1, "otherName"));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, canAddOneDevice)
{
    ASSERT_TRUE(adder.tryToAdd(device1));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, canAddMultipleDevices)
{
    adder.tryToAdd(device1);
    ASSERT_TRUE(adder.tryToAdd(device2));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, cannotAddOneDeviceTwice)
{
    adder.tryToAdd(device1);
    ASSERT_FALSE(adder.tryToAdd(device1));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, canListAddedDevices)
{
    adder.tryToAdd(device1);
    adder.tryToAdd(device2);
    auto list = accesor.listDevices();
    ASSERT_TRUE(exists(list, device1));
    ASSERT_TRUE(exists(list, device2));
}

TEST_F(DevicesManagerWithTwoDevicesFixture, canListRejectedDevices)
{
    adder.tryToAdd(device1);
    adder.tryToAdd(device1);
    auto list = accesor.listRejectedDevices();
    ASSERT_TRUE(exists(list, device1));
}

TEST_F(DevicesManagerFixture, searchForDevicesCallsNetworkSender)
{
    EXPECT_CALL(sender, send(searchReq));
    accesor.searchForNewDevices();
}



bool exists(std::set< Directory > list, Directory & directory)
{
    return std::find(list.begin(), list.end(), directory)
        != list.end();
}

TEST(ComponentsTreeTest, canAddDirectory)
{
    Directory mainDir{"mainDir"};
    ComponentsTreeAccesor & sut = mainDir;
    Directory dir1{"dir1"};
    ASSERT_TRUE(sut.tryToAdd(dir1));
}

//implement tests that check if making changes in listed components and devices
// do no changes in the original instances

TEST(ComponentsTreeTest, canListAddedDirectories)
{
    Directory mainDir{"mainDir"};
    ComponentsTreeAccesor & sut = mainDir;
    Directory dir1{"dir1"};
    Directory dir2{"dir2"};
    sut.tryToAdd(dir1);
    sut.tryToAdd(dir2);
    auto list = sut.listDirectories();
    ASSERT_TRUE(exists(list, dir1));
    ASSERT_TRUE(exists(list, dir2));
}

//TEST(ComponentsTreeTest, canAddDirectoryOneToAnother)

/*
TEST_F(DevicesManagerFixture, rejectedDevicesListIsClearedBeforeSearch)
{
    Device device1{"name1", "type1"};
    Device device2{"name1", "type1"};
    adder.tryToAdd(device1);
    adder.tryToAdd(device2);
    auto list = accesor.listRejectedDevices();
    ASSERT_TRUE(exists(list, device2));
}

TEST_F(DevicesManagerFixture, changingNameToExistingOneReturnsFalse)
{

}

TEST_F(DeviceContainerFixture, canUseTryToAddMethod)
{
    Device device{"name", "type"};
    ASSERT_TRUE(adder.tryToAdd(device));
}

TEST_F(OneDeviceContainerFixture, canAddAndListOneDevice)
{
    adder.tryToAdd(device);
    ASSERT_EQ(name, getter.list()[0]);
}

TEST_F(OneDeviceContainerFixture, canGetAddedDevice)
{
    adder.tryToAdd(device);
    ASSERT_EQ(device, getter.get(name));
}

TEST_F(TwoDevicesContainerFixture, canAddAndListTwoDevicesAlphabeticaly)
{
    adder.tryToAdd(device2);
    adder.tryToAdd(device1);
    NamesList namesList = getter.list();
    ASSERT_EQ(name2, namesList[1]);
    ASSERT_EQ(name1, namesList[0]);
}

TEST_F(TwoDevicesContainerFixture, cannotAddTwoEqualDevices)
{
    ASSERT_TRUE(adder.tryToAdd(device1));
    ASSERT_FALSE(adder.tryToAdd(device1));
}

class MockNetworkClientSender : public NetworkClientSender
{
public:
    MOCK_METHOD(void, send, (Message), (override));
};

class MainDevicesKeeper : public DevicesManager
{
    std::shared_ptr<MockNetworkClientSender> sender;

public:
    MainDevicesKeeper(std::shared_ptr<MockNetworkClientSender> & sender)
    { this->sender = sender; }
    void searchForNewDevices() override;
    NamesList listNewDevices() override;
    NamesList listKnownDevices() override;
};

void MainDevicesKeeper::searchForNewDevices()
{
    sender->send();
}

NamesList MainDevicesKeeper::listNewDevices()
{
    NamesList list{};
    return list;
}

NamesList MainDevicesKeeper::listKnownDevices()
{
    NamesList list{};
    return list;
}

TEST(DevicesMenagerFeatures, canSearchForNewDevices)
{
    std::shared_ptr<MockNetworkClientSender> sender;
    Message msg = "message1";
    EXPECT_CALL(*sender, send(msg));
    std::unique_ptr<DevicesManager> manager
        = std::make_unique<MainDevicesKeeper>(sender);
    manager->searchForNewDevices();
}
*/