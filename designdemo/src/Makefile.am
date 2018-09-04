# Makefile.am
AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = MessageDispatch
MessageDispatch_SOURCES = MessageHandler.h \
				InputMsgHandler.h InputMsgHandler.cpp \
				OutputMsgHandler.h OutputMsgHandler.cpp \
				MessageDispatch.h MessageDispatch.cpp \
				Task.h PrintTask.h PrintTask.cpp \
				ThreadPool.h ThreadPool.cpp \
				StringBeads.h StringBeads.cpp \
				main.cpp
MessageDispatch_CPPFLAGS = -std=c++11 
MessageDispatch_LDFLAGS = -pthread
