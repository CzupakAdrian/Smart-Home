#include "../googletest/googletest/include/gtest/gtest.h"
#include "../NetworkInterfaces.hpp"
#include "../DevicesContainerInterfaces.hpp"
#include "../Device.hpp"
#include "../DevicesContainer.hpp"
#include <memory>

using namespace SmartHome;

struct OneDeviceContainerFixture : public testing::Test
{
    std::string name{"device 1"};
    Device device{name};
    DevicesContainer container{};
    DevicesAdder & adder = container;
    DevicesGetter & getter = container;
};

struct TwoDevicesContainerFixture : public testing::Test
{
    std::string name1{"device 1"};
    std::string name2{"device 2"};
    Device device1{name1};
    Device device2{name2};
    DevicesContainer container{};
    DevicesAdder & adder = container;
    DevicesGetter & getter = container;
};

TEST(SystemTest, shouldPass)
{
    ASSERT_TRUE(true);
}

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

/*
class DevicesFinder
{
    virtual void search() = 0;
    virtual NamesList list() = 0;
};

class UnknownDevicesFinder : public DevicesFinder
{

public:
    void search() override;
    NamesList list() override;
};
*/
/*
using Message = std::string;

class DevicesReceiver : public NetworkClientReceiver
{
    DevicesContainer devices;
public:
    void receive(Message) override;
};

void DevicesReceiver::receive(Message)
{
    Device device{"dev"};
    devices.tryToAdd(device);
}

TEST(DevicesFinderFeatures, canStoreReceivedDevices)
{
    auto devices = findDevices();


    
}
*/