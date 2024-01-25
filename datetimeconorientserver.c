// ITERATIVE CONNECTIONLESS SERVER PROG FOR DATE AND TIME

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<arpa/inet.h>
main()
{
int sockfd,j,servlen;
char msg[40];
struct sockaddr_in sa;
time_t pt;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
perror("socket not created");
exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(57022);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
printf("Socket created\n");
j=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{
perror("bind error");
exit(0);
}

while(1)
{
servlen=sizeof(sa);
recvfrom(sockfd,msg,sizeof(msg),0,(struct sockaddr *)&sa,&servlen);
pt=time(NULL);
strcpy(msg,ctime(&pt));
sendto(sockfd,msg,sizeof(msg),0,(struct sockaddr *)&sa,sizeof(sa));
}
close(sockfd);
}

