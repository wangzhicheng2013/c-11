g++ -std=c++11 -g -o udpserver main.cpp SocketConfig.h SocketConfig.cpp SocketUtility.h SocketUtility.cpp UdpThread.h UdpThread.cpp UdpTheadForRadius.h UdpTheadForRadius.cpp UdpServer.h UdpServer.cpp -levent -pthread
g++ -std=c++11 -g -o udpclient udpclient.cpp
