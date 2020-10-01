#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NetworkInterfaces.hpp"
#include "Device.hpp"
#include "DevicesContainer.hpp"
#include "AppInterfaces.hpp"
#include "BasicDefinitions.hpp"
#include <memory>
#include <algorithm>

using namespace SmartHome;

class DevicesManager
    : DevicesAccesor
    , DevicesConfigurator
{

};

struct DevicesContainerFixture : public testing::Test
{
    DevicesContainer sut{};

};

TEST(SystemTest, shouldPass)
{
    ASSERT_TRUE(true);
}
/*
TEST_F(OneDeviceContainerFixture, canUseTryToAddMethod)
{
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