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
				IP.h IP.cpp \
				KafkaClientConfig.h KafkaClientConfig.cpp \
				KafkaProducerClient.h KafkaProducerClient.cpp \
				KafkaConsumerClient.h KafkaConsumerClient.cpp \
				MemoryBlock.h MemoryBlock.cpp \
				RedisClient.h RedisClient.cpp \
				RedisClientPool.h RedisClientPool.cpp \
				Pointer.h Pointer.cpp \
				Shape.h Shape.cpp \
				Square.h Square.cpp \
				SockectUtility.h SockectUtility.cpp \
				HttpConig.h HttpConfig.cpp \
				UrlMapper.h UrlMapper.cpp \
				HttpKey.h HttpKey.cpp \
				ResponseHandler.h ResponseHandler.cpp \
				EchoResponseHandler.h EchoResponseHandler.cpp \
				HttpUtility.h HttpUtility.cpp \
				HttpThread.h HttpThread.cpp \
				HttpServer.h HttpServer.cpp \
				ResponseHandlerInfo.h ResponseHandlerInfo.cpp \
				main.cpp
MessageDispatch_CPPFLAGS = -std=c++11 \
			 -I ./
MessageDispatch_LDFLAGS = -pthread 
MessageDispatch_LDADD = -lrdkafka++ -lrdkafka -lhiredis -levent_pthreads -levent_openssl -levent
