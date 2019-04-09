/*
 * PingUtility.cpp
 *
 *  Created on: 2019-4-8
 *      Author: root
 */

#include "PingUtility.h"
PingUtility PingUtility::pingUtility;
PingUtility::PingUtility() {
	// TODO Auto-generated constructor stub
	pid = getpid();
	memset(buf, 0, BUF_SIZE);
	sockfd = -1;
	if (false == Init())
	{
		exit(EXIT_FAILURE);
	}
}
unsigned short PingUtility::CheckSum(unsigned short *addr, int len)
{
    unsigned int sum = 0;
    while (len > 1)
    {
        sum += *addr++;
        len -= 2;
    }
    if (1 == len)
    {
        sum += *(reinterpret_cast<unsigned char *>(addr));
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return static_cast<unsigned short>(~sum);
}
float PingUtility::TimeDiff(struct timeval *begin, struct timeval *end)
{
    int n = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);
    return 1.0 * n / 1000;
}
void PingUtility::Pack(icmp *icmp, int sequence)
{
    icmp->type = ICMP_ECHO;
    icmp->id = getpid();
    icmp->sequence = sequence;
    gettimeofday(&icmp->timestamp, 0);
    icmp->checksum = CheckSum((unsigned short *)icmp, ICMP_SIZE);
}
int PingUtility::UnPack(char *buf, int len, char *addr)
{
    ip *ip = reinterpret_cast<struct ip *>(buf);
    int ipheadlen = (ip->hlen) << 2;
    icmp *icmp = reinterpret_cast<struct icmp *>(buf + ipheadlen);
    struct timeval end;
    len -= ipheadlen;
    if (len < 8)
    {
        printf("ICMP packets\'s length is less than 8 \n");
        return -1;
    }
    if (icmp->type != ICMP_ECHOREPLY || icmp->id != pid)
    {
        printf("ICMP packets are not send by us \n");
        return -1;
    }
    gettimeofday(&end, 0);
    float rtt = TimeDiff(&icmp->timestamp, &end);
    printf("%d bytes from %s : icmp_seq = %u ttl = %d rtt = %fms \n", len, addr, icmp->sequence, ip->ttl, rtt);
    return 0;
}
bool PingUtility::Init()
{
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        printf("socket() error \n");
        return false;
    }
    return true;
}
void PingUtility::Ping(PingRes &pingRes)
{
	struct icmp sendicmp = {0};
	struct sockaddr_in from = {0};
	struct sockaddr_in to = {0};
	socklen_t fromlen = 0;
	int nsend = 0;
	int nreceived = 0;
	int n = 0;
    GetDestAddr(to, pingRes);
    for (int i = 0; i < pingRes.pack_num;i++)
    {
        nsend++;
        memset(&sendicmp, 0, ICMP_SIZE);
        Pack(&sendicmp, nsend);
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
        if (-1 == UnPack(buf, n, inet_ntoa(from.sin_addr)))
        {
            printf("unpack() error \n");
        }
    }
    pingRes.send_num = nsend;
    pingRes.recv_num = nreceived;
    pingRes.loss_rate = (nsend - nreceived) / nsend * 100;
}
void PingUtility::GetDestAddr(struct sockaddr_in &to, PingRes &pingRes)
{
    to.sin_family = AF_INET;
	in_addr_t inaddr = inet_addr(pingRes.ping_path);
    if (INADDR_NONE == inaddr)
    {
    	struct hostent *host = nullptr;
        if (NULL == (host = gethostbyname(pingRes.ping_path)))
        {
            printf("gethostbyname() error \n");
            exit(EXIT_FAILURE);
        }
        to.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    }
    else
    {
        to.sin_addr.s_addr = inaddr;
    }
}
PingUtility::~PingUtility()
{
	// TODO Auto-generated destructor stub
	if (sockfd > 0)
	{
		close(sockfd);
		sockfd = -1;
	}
}
