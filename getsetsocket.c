#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/uio.h>
main()
{
	int sockfd,j;
	char msg1[20]="Junaid",msg2[20]=" Nihan",msg3[20];
	struct sockaddr_in sa;
	struct iovec iov1[2],iov2[2];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("\n Socket not created");
		exit(0);
	}
	sa.sin_family=AF_INET;
	sa.sin_port=htons(7);
	sa.sin_addr.s_addr=inet_addr("192.100.100.6");
	j=connect(sockfd,(struct sockaddr *) &sa,sizeof(sa));
	if(j<0)
	{
		perror("\n Connection not established");
		exit(0);
	}
	iov1[0].iov_base=&msg1;
	iov1[0].iov_len=strlen(msg1);
	iov1[1].iov_base=&msg2;
	iov1[1].iov_len=strlen(msg2);
	iov2[0].iov_base=&msg3;
	iov2[0].iov_len=30;
	writev(sockfd,iov1,2);
	readv(sockfd,iov2,2);
	printf("\n %s",msg3);
	close(sockfd);
}
