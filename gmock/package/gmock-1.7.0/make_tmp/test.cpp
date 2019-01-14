#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
using ::testing::Return;
class Message
{
public:
    virtual string Get() = 0;
};
class MockMessage : public Message
{
public:
    MOCK_METHOD0(Get, string());
};
string fun(Message *p)
{
    string str = p->Get();
    return str;
}
TEST(TestMessage, TestOK)
{
    MockMessage msg;
    string str = "hello world";
    EXPECT_CALL(msg, Get()).WillRepeatedly(Return(str));
    EXPECT_EQ(str, fun(&msg));
}
