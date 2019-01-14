g++ -I ../gtest/include  -g -Wall -Wextra -lgtest -pthread -c ./test.cpp
g++ -I ../gtest/include -g -Wall -Wextra -lgtest -lgmock -pthread -lpthread test.o  -o test
