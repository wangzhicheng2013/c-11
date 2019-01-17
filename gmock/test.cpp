#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
using ::testing::Return;
using ::testing::Action;
using ::testing::DefaultValue;
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
class Request
{
};
class Response
{
public:
    int x;
    int y;
};
class Client
{
public:
    bool Query(const Request &req, Response &resp)
    {
        return true;
    }
};
class MockClient : public Client
{
public:
    MOCK_METHOD2(Query, bool(const Request &, Response &));
};
bool ConnectServer(Client &client, Response &resp)
{
    Request req;
    return client.Query(req, resp);
}
TEST(TestMessage, TestOK)
{
    MockMessage msg;
    string str = "hello world";
    EXPECT_CALL(msg, Get()).WillRepeatedly(Return(str));
    EXPECT_EQ(str, fun(&msg));
}
TEST(TestClient, TestOK)
{
    MockClient mockClient;
    Request req;
    Response resp;
    resp.x = 10;
    resp.y = 20;
    EXPECT_CALL(mockClient, Query(testing::_,testing::_)).WillOnce(DoAll(testing::SetArgReferee<1>(resp), testing::Return(true)));
    EXPECT_TRUE(ConnectServer(mockClient, resp));
    //EXPECT_EQ(10, resp.x);
    //EXPECT_EQ(20, resp.y);
}
