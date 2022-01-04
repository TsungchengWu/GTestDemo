#include <gtest/gtest.h>
#include "function.h"
namespace{

TEST(ExampleTest, HelloWorld)
{
     EXPECT_TRUE(true);
     EXPECT_EQ(1, 1);
}

TEST(ExampleTest, Square)
{
     EXPECT_EQ(1, Square(1));
     EXPECT_EQ(4, Square(2));
     EXPECT_EQ(9, Square(3));
     EXPECT_EQ(16, Square(4));
     EXPECT_EQ(25, Square(5));
}

} // namespace