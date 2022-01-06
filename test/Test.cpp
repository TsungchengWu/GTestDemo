#include <iostream>
#include <gtest/gtest.h>
#include "function.h"
using namespace std;

namespace{

Demo demo1;
// 前者为套件名称，后者为测试名称，都不应包含"_"
TEST(ExampleTest, SetX)
{
     demo1.SetX(2);
     EXPECT_EQ(2, demo1.GetX());
}

TEST(ExampleTest, AddX)
{
     demo1.SetX(0);
     EXPECT_EQ(0, demo1.GetX());
     EXPECT_EQ(0, demo1.GetX());
     EXPECT_EQ(0, demo1.GetX());
     for(int i=0; i<10; ++i){
          demo1.AddX(1);
          EXPECT_EQ(i+1, demo1.GetX());
     }
}
/*************************end*************************/

/*
可以通过参数化测试，避免大量罗列测试用例
*/
class ExampleTestWithParam : public testing::TestWithParam<int> {
};

TEST_P(ExampleTestWithParam, MulX) {
  EXPECT_LT(0, demo1.MulX(GetParam()));
}

// 还可以使用Range、ValuesIn、combine等生成测试用例
INSTANTIATE_TEST_SUITE_P(ValuesInput,
                         ExampleTestWithParam,
                         testing::Values(1, 2, 3, 4, 5));
INSTANTIATE_TEST_SUITE_P(RangeInput,
                         ExampleTestWithParam,
                         testing::Range(1, 6, 1));
/*************************end*************************/

/*
如果要编写两个或多个对类似数据进行操作的测试，可以使用测试装置，其能够为多个不同的测试重用相同的对象配置。
 per-test setup/tear-down
*/
class FixtureTest : public ::testing::Test{
protected:
     virtual void SetUp() override {
          obj = new Demo;
          obj->SetX(100);
     }

     virtual void TearDown() override {
          if(obj != nullptr){
               delete obj;
               obj = nullptr;
          }
     }

     Demo* obj;
};

TEST_F(FixtureTest, MathLibTest1){
     // 1.构造一个FixtureTest对象
     // 2.默认执行SetUp();
     EXPECT_EQ(400, obj->MulX(4));
     // 4.默认执行TearDown();
     // 5.FixtureTest对象被析构
}
TEST_F(FixtureTest, MathLibTest2){
     // 1.构造一个FixtureTest对象
     // 2.默认执行SetUp();
     EXPECT_EQ(500, obj->MulX(5));
     // 4.默认执行TearDown();
     // 5.FixtureTest对象被析构
}
/**************************end************************/

/*
有时测试使用的资源设置起来代价很昂贵，那么可以让多个测试使用同一个资源，只需要一次资源设置。
 per-test suite setup/tear-down
*/
class FooTest : public testing::Test {
protected:
  static void SetUpTestSuite() {
      shared_resource_ = new Demo;
      shared_resource_->SetX(100);
  }

     static void TearDownTestSuite() {
          if (shared_resource_ == nullptr){
               delete shared_resource_;
               shared_resource_ = nullptr;
          }
     }

  static Demo* shared_resource_;
};

Demo* FooTest::shared_resource_ = nullptr;

// SetUpTestSuite()
TEST_F(FooTest, Test1) {
     EXPECT_EQ(200, shared_resource_->MulX(2));
}
TEST_F(FooTest, Test2) {
     EXPECT_EQ(500, shared_resource_->MulX(5));
}
// TearDownTestSuite()

/**************************end**************************/

} // namespace