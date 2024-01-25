// ITERATIVE CONNECTIONLESS CLIENT PROG FOR DATE AND TIME

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
char buff1[40],buff2[40];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
 perror("socket not created");
 exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(57022);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
printf("enter a message: ");
scanf("%s",buff1);
sendto(sockfd,buff1,40,0,(struct sockaddr *)&sa,sizeof(sa));
servlen=sizeof(sa);
recvfrom(sockfd,buff2,40,0,(struct sockaddr *)&sa,&servlen);
printf("Date and Time is %s\n",buff2);
close(sockfd);
}

