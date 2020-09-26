#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Example.hpp"

TEST(SystemTest, shouldPass)
{
    ASSERT_TRUE(true);
}

TEST(SystemTest, shouldPassWithCall)
{
    ASSERT_TRUE(getTrue());
}
