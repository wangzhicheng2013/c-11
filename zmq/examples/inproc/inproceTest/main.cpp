#include <zmq.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <thread>
using namespace std;
static const int SIZE = 1024;
static const int LOOP = 1000000;
const char *address = "inproc://#0";
char buf[SIZE] = "";
bool MainThread()
{
    void *context = zmq_ctx_new();
    void *server = zmq_socket(context, ZMQ_SUB);
    if (nullptr == context || nullptr == server)
    {
        cerr << "server socket init failed...!" << endl;
        return false;
    }
    zmq_bind(server, address);
    while (true)
    {
        zmq_msg_t message;
        zmq_msg_init(&message);
        zmq_msg_recv(&message, server, 0);
        zmq_msg_close(&message);
    }
    zmq_close(server);
    zmq_term(context);
    return true;
}
bool ChildThread()
{
    void *context = zmq_ctx_new();
    void *client = zmq_socket(context, ZMQ_PUB);
    if (nullptr == context || nullptr == client)
    {
        cerr << "client socket init failed...!" << endl;
        return false;
    }
    sleep(2);
    zmq_connect(client, address);
    int sendcnt = 0;
    struct timeval startTime, endTime;
    gettimeofday(&startTime, nullptr);
    for (int i = 0;i < LOOP;i++)
    {
        zmq_msg_t message;
        zmq_msg_init_size(&message, SIZE);
        memcpy(zmq_msg_data(&message), buf, SIZE);
        if (SIZE == zmq_msg_send(&message, client, 0))
        {
            sendcnt++;
        }
        else
        {
            cerr << "send failed...!" << endl;
        }
        zmq_msg_close(&message);
    }
    zmq_close(client);
    zmq_term(context);
    gettimeofday(&endTime, nullptr);
    long timeUse = 1000000 * (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec);
    cout << "records = " << sendcnt << " elapsed time = " << timeUse / 1e3 << "ms" << endl;
    return true;
}
int main()
{
    for (int i = 0;i < SIZE - 1;i++)
    {
        buf[i] = 'A';
    }
    thread th0(MainThread);
    thread th1(ChildThread);
    th0.join();
    th1.join();

    return 0;
}
