// ITERATIVE CONNECTIONLESS SERVER PROG FOR CHARACTER GENERATION. 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
main()
{
int sockfd,j,servlen,i,k;
char msg[300];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
perror("socket not created");
exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(5402);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
j=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{
perror("bind error");
exit(0);
}
while(1)
{
k=0;
servlen=sizeof(sa);
recvfrom(sockfd,msg,sizeof(msg),0,(struct sockaddr *)&sa,&servlen);
for(i=1;i<255;i++)
{
msg[k]=i;
k++;
}
msg[k]='\0';
sendto(sockfd,msg,sizeof(msg),0,(struct sockaddr *)&sa,sizeof(sa));
}
close(sockfd);
}

