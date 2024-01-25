#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int sockfd,fpn,j,len;
	char fmsg[50],msg[50];
	struct sockaddr_in sa;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("\n Socket not created");
		exit(0);
	}
	sa.sin_family=AF_INET;
	sa.sin_port=htons(13);
	sa.sin_addr.s_addr=inet_addr("10.2.0.5");
	j=connect(sockfd,(struct sockaddr *) &sa,sizeof(sa));
	if(j<0)
	{
		perror("\n Connection not established");
		exit(0);
	}
	len=sizeof(sa);
	getpeername(sockfd,(struct sockaddr *) &sa,&len);
	inet_ntop(AF_INET,&sa.sin_addr,fmsg,sizeof(fmsg));
	printf("\n The foreign address is %s",fmsg);
	printf("\n The foreign port no is %d",ntohs(sa.sin_port));
	close(sockfd);
}
