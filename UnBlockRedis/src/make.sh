g++ -std=c++11 -g -o testRedis main.cpp RedisClient.h RedisClient.cpp blockingconcurrentqueue.h CpuBinding.h CpuBinding.cpp -I ./  -lhiredis -lrt  -pthread
