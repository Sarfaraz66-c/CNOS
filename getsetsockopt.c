#include<stdio.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<sys/socket.h>
main()
{
	int sockfd,maxseg,sendbuff,optlen;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("\n Socket can't be created\n");
	}
	optlen=sizeof(maxseg);
	if(getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG,(char*)&maxseg,&optlen)<0);
	//perror("\nTCP MAX_SEG getsocketopt error");
	printf("TCP maxseg=%d\n",maxseg);
	sendbuff=2048
;
	if(setsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char*)&sendbuff,sizeof(sendbuff))<0)
		perror(sizeof(sendbuff));
	if(getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char*)&sendbuff,&optlen)<0)
	perror("SO_SNDBUFF getsockopt error");
	printf("sen buffer size=%d\n",sendbuff);
}
