#include "../googletest/googletest/include/gtest/gtest.h"
#include "../NetworkInterfaces.hpp"
#include "../DevicesContainerInterfaces.hpp"
#include "../Device.hpp"
#include "../DevicesContainer.hpp"
#include <memory>

using namespace SmartHome;

TEST(SystemTest, shouldPass)
{
    ASSERT_TRUE(true);
}

bool DevicesContainer::tryToAdd(Device) { return true; }

TEST(DevicesContainerTests, canUseTryToAddMethod)
{
    Device device{};
    DevicesContainer container{};
    DevicesAdder & adder = container;
    EXPECT_TRUE(adder.tryToAdd(device));
}
