/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-23
Description:program main entry
ChangeLog:
			1. create this file
 **************************************************/
#include "SingleInstance.h"
#include "StringOp.h"
#include <gtest/gtest.h>
using namespace stringop;
TEST(SingleInstanceTest, TestOK)
{
	class Test1
	{
	public:
		int test;
	};
	class Test2
	{
	public:
		string test;
	};
	Test1 *pTest1 = SingleInstance<Test1>::Instance();
	pTest1->test = 10;
	Test2 *pTest2 = SingleInstance<Test2>::Instance();
	pTest2->test = "hello world";
}
TEST(StringOp_Erase, EraseOk)
{
	string str = "abcad";
	string delstr = "ab";
	StringOp::Erase(str, delstr);
	cout << str << endl;
	EXPECT_EQ(str, "cd");
}
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
