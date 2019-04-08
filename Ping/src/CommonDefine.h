/*
 * CommonDefine.h
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#ifndef COMMONDEFINE_H_
#define COMMONDEFINE_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
typedef struct icmp
{
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
    struct timeval  timestamp;
}icmp;
typedef struct ip
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned char hlen:4;
    unsigned char version:4;
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned char version:4;
    unsigned char hlen:4;
#endif
    unsigned char tos;         	// 服务类型
    unsigned short len;        	// 总长度
    unsigned short id;         	// 标识符
    unsigned short offset;     	// 标志和片偏移
    unsigned char ttl;         	// 生存时间
    unsigned char protocol;    	// 协议
    unsigned short checksum;   	// 校验和
    struct in_addr ipsrc;    	// 32位源ip地址
    struct in_addr ipdst;   	// 32位目的ip地址
}ip;
static const unsigned char ICMP_ECHO = 8;
static const unsigned char ICMP_ECHOREPLY = 0;
static const size_t BUF_SIZE = 1024;
static const size_t ICMP_SIZE = sizeof(struct icmp);

#endif /* COMMONDEFINE_H_ */
