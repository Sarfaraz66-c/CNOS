#include<stdio.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<sys/socket.h>
main()
{
int sockfd,maxseg,sendbuff,optlen;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
{
perror("\n socket cant be created");
}
optlen=sizeof(maxseg);
if(getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG,(char *)&maxseg,&optlen)<0)
perror("\n TCP MAX-SEG getsockopt error");
printf("TCP maxseg=%d \n",maxseg);
sendbuff=16384;
if(setsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char *)&sendbuff,sizeof(sendbuff))<0)
perror("SO_SNDBUFF setsockopt error");
optlen=sizeof(sendbuff);
if(getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char *)&sendbuff,&optlen)<0)
perror("SO_SNDBUF getsockopt error");
printf("sen buffer size=%d \n",sendbuff);
}
