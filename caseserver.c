// case server - client

#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<netinet/in.h>
main(int argc,char *argv[])
{
int sockfd,j;
char msg1[40],msg2[40];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
 {
   perror("socket not created");
   exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(atoi(argv[2]));
sa.sin_addr.s_addr=inet_addr(argv[1]);
j=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{
  perror("connection not established");
  exit(0);
}
printf("\n enter message");
scanf("%s",msg1);
//printf("\n enter 1 to convert lower to upper and \n 2 to convert upper to lower \n enter choice");
//scanf("%d",&ch);
send(sockfd,msg1,40,0);
//send(sockfd,(char *)ch,sizeof(ch),0);
recv(sockfd,msg2,40,0);
printf("\n message is %s\n",msg2);
close(sockfd);
}

