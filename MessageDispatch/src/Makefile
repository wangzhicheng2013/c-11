CC=gcc
DBG= -D__LINUX__ -DUTIL_DEBUG
ifndef DEBUG_SET
	DEBUG_SET=-g
endif
IFLAGS=-I./
LIBS=-L.\
	-pthread
LINK=-Wl,-rpath\
	-Wl,-rpath=../libs
TARGET=AuthorityMessageDispatch
all:$(TARGET)
OBJS=AuthorityMessageDispatch.o\
	main.o
$(TARGET):$(OBJS)
	$(CC) -fPIC -o ./$(TARGET) $(OBJS) $(LIBS) $(LINK)
.cpp.o:
	$(CC) $(DBG) $(DEBUG_SET) $(IFLAGS) -fPIC -c $<
clean:
	rm -rf *.o
	rm -f AuthorityMessageDispatch
