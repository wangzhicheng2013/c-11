#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
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
void fun(Message *p)
{
    string str = p->Get();
}
TEST(TestMessage, TestOK)
{
    MockMessage msg;
    string str = "hello world";
    EXPECT_CALL(msg, Get()).WillRepeatedly(Return(ByRef(str)));
    EXPECT_EQ(str, fun(&msg));
}
int main()
{
    return 0;
}
