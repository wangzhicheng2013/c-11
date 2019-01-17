g++ -I ../gtest/include -I ../include -g -Wall -Wextra -lgtest -pthread -c ./test.cpp 
g++ -I ../gtest/include -I ../include -g -Wall -Wextra -lgtest -pthread -lpthread test.o gmock_main.a -o gmock_test
