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

TEST_F(TwoDevicesContainerFixture, canAddAndListTwoDevices)
{
    adder.tryToAdd(device1);
    adder.tryToAdd(device2);
    auto list = getter.list();
    ASSERT_EQ(name1, list[1]);
    ASSERT_EQ(name2, list[0]);
}

TEST_F(OneDeviceContainerFixture, canGetAddedDevice)
{
    adder.tryToAdd(device);
    ASSERT_EQ(device, getter.get(name));
}

