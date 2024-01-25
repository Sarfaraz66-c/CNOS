// ITERATIVE CONNECTIONLESS SERVER PROG FOR ECHO SERVER

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
main()
{
int sockfd,j,servlen;
struct sockaddr_in sa;
char msg1[100],msg2[100];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
  perror("socket not created");
  exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(6534);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
j=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0){
 perror("bind error");
 exit(0);
}
while(1)
{
servlen=sizeof(sa);
recvfrom(sockfd,msg2,sizeof(msg2),0,(struct sockaddr *)&sa,&servlen);
sendto(sockfd,msg2,sizeof(msg2),0,(struct sockaddr *)&sa,sizeof(sa));
}
close(sockfd);
}







