CC=g++
DBG=-std=c++11 -D__LINUX__ -DUTIL_DEBUG
ifndef DEBUG_SET
	DEBUG_SET=-g
endif
IFLAGS=-I./
LIBS=-L.\
	-levent\
	-pthread
LINK=-Wl,-rpath\
	-Wl,-rpath=../libs
TARGET=Test
all:$(TARGET)
OBJS=FileWatchNotifyConfig.o\
    FileWatchNotify.o\
    EsFileWatchNotify.o\
	main.o
$(TARGET):$(OBJS)
	$(CC) -fPIC -o ./$(TARGET) $(OBJS) $(LIBS) $(LINK)
.cpp.o:
	$(CC) $(DBG) $(DEBUG_SET) $(IFLAGS) -fPIC -c $<
clean:
	rm -rf *.o
	rm -f Test
