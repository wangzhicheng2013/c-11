CC=g++
DBG=-std=c++11 -D__LINUX__ -DUTIL_DEBUG
ifndef DEBUG_SET
	DEBUG_SET=-g
endif
IFLAGS=-I./
LIBS=-L.\
	-levent\
	-lhiredis\
	-pthread
LINK=-Wl,-rpath\
	-Wl,-rpath=../libs
TARGET=RedisSubscribe
all:$(TARGET)
OBJS=RedisSubscriber.o\
	subscriber_main.o
$(TARGET):$(OBJS)
	$(CC) -fPIC -o ./$(TARGET) $(OBJS) $(LIBS) $(LINK)
.cpp.o:
	$(CC) $(DBG) $(DEBUG_SET) $(IFLAGS) -fPIC -c $<
clean:
	rm -rf *.o
	rm -f RedisSubscribe
