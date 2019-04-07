// https://blog.csdn.net/vevenlcf/article/details/46725645
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
static const unsigned char ICMP_ECHO = 8;
static const unsigned char ICMP_ECHOREPLY = 0;
static const size_t BUF_SIZE = 1024;
static const int NUM = 5;
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
    unsigned char tos;             // 服务类型
    unsigned short len;             // 总长度
    unsigned short id;                // 标识符
    unsigned short offset;            // 标志和片偏移
    unsigned char ttl;            // 生存时间
    unsigned char protocol;       // 协议
    unsigned short checksum;       // 校验和
    struct in_addr ipsrc;    // 32位源ip地址
    struct in_addr ipdst;   // 32位目的ip地址
}ip;
const size_t ICMP_SIZE = sizeof(struct icmp);
unsigned short checkSum(unsigned short *addr, int len)
{
    unsigned int sum = 0;  
    while (len > 1)
    {
        sum += *addr++;
        len -= 2;
    }
    if (1 == len)
    {
        sum += *(unsigned char *)addr;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short) ~sum;
}
float timediff(struct timeval *begin, struct timeval *end)
{
    int n = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);
    return (float) (n / 1000);
}
void pack(struct icmp *icmp, int sequence)
{
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->id = getpid();
    icmp->sequence = sequence;
    gettimeofday(&icmp->timestamp, 0);
    icmp->checksum = checkSum((unsigned short *)icmp, ICMP_SIZE);
}
int unpack(char *buf, int len, char *addr)
{
    int ipheadlen = 0;
    struct ip *ip = (struct ip *)buf;
    ipheadlen = (ip->hlen) << 2;
    struct icmp *icmp = (struct icmp *)(buf + ipheadlen);
    struct timeval end; 
    len -= ipheadlen;
    if (len < 8)
    {
        printf("ICMP packets\'s length is less than 8 \n"); 
        return -1;
    }
    if (icmp->type != ICMP_ECHOREPLY || icmp->id != getpid())
    {    
        printf("ICMP packets are not send by us \n");
        return -1;
    }
    gettimeofday(&end, 0);
    float rtt = timediff(&icmp->timestamp, &end);
    printf("%d bytes from %s : icmp_seq=%u ttl=%d rtt=%fms \n", len, addr, icmp->sequence, ip->ttl, rtt);
    return 0;
}
char buf[BUF_SIZE] = {0};
int main(int argc, char *argv[])
{
    struct hostent *host = nullptr;
    struct icmp sendicmp = {0};
    struct sockaddr_in from = {0};
    struct sockaddr_in to = {0};
    socklen_t fromlen = 0;
    int sockfd = 0;
    int nsend = 0;
    int nreceived = 0;
    int i, n;
    in_addr_t inaddr = {0};
    if (argc < 2)
    {
        printf("use : %s hostname/IP address \n", argv[0]);
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        printf("socket() error \n");
        exit(1);
    }
    to.sin_family = AF_INET;
    inaddr = inet_addr(argv[1]);
    if (INADDR_NONE == inaddr)
    {
        if (NULL == (host = gethostbyname(argv[1])))
        {
            printf("gethostbyname() error \n");
            exit(1);
        }
        to.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    }
    else
    {
        to.sin_addr.s_addr = inaddr;
    }
    printf("ping %s (%s) : %d bytes of data.\n", argv[1], inet_ntoa(to.sin_addr), (int)ICMP_SIZE);
    for (i = 0; i < NUM;i++)
    {
        nsend++;
        memset(&sendicmp, 0, ICMP_SIZE);
        pack(&sendicmp, nsend);
        if (-1 == sendto(sockfd, &sendicmp, ICMP_SIZE, 0, (struct sockaddr *)&to, sizeof(to)))
        {
            printf("sendto() error \n");
            continue;
        }
        if ((n = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&from, &fromlen)) < 0)
        {
            printf("recvform() error \n");
            continue;
        }
        nreceived++;
        if(-1 == unpack(buf, n, inet_ntoa(from.sin_addr)))
        {
            printf("unpack() error \n");
        }
        sleep(1);
    }
    printf("---  %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %%%d packet loss\n", nsend, nreceived,  (nsend - nreceived) / nsend * 100);

    return 0;
}
