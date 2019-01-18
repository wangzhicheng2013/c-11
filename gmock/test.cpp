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
public:
    int a;
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
    virtual bool Query(const Request &req, Response &resp)
    {
        return false;
    }
};
class MockClient : public Client
{
public:
    MOCK_METHOD2(Query, bool(const Request &, Response &));
};
bool ConnectServer(Client *client, int &res)
{
    Request req;
    Response resp;
    if (client->Query(req, resp))
    {
        cout << resp.x << endl;
        res = resp.x + resp.y;
        return true;
    }
    return false;
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
    EXPECT_CALL(mockClient, Query(testing::_,testing::_)).WillRepeatedly(DoAll(testing::SetArgReferee<1>(resp), testing::Return(true)));
    int res = 0;
    EXPECT_TRUE(ConnectServer(&mockClient, res));
    EXPECT_EQ(30, res);
}
