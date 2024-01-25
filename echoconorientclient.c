// ITERATIVE CONNECTIONLESS CLIENT PROG FOR ECHO SERVER

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
main()
{
int sockfd,servlen;
char buff1[20],buff2[20];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
 perror("socket not created");
 exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(6534);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
printf("enter a message: ");
scanf("%s",buff1);
sendto(sockfd,buff1,20,0,(struct sockaddr *)&sa,sizeof(sa));
servlen=sizeof(sa);
recvfrom(sockfd,buff2,20,0,(struct sockaddr *)&sa,&servlen);
printf("message is %s",buff2);
}

