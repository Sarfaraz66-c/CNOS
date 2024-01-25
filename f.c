// file access using sockets - client

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/file.h>
#include<stdlib.h>

main()
{
int sockfd,j;
struct sockaddr_in sa;
char msg[20],msg1[250];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
perror("socket not created");
exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(6133);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
j=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{
perror("connection not created");
exit(0);
}
printf("Enter name of file : ");
scanf("%s",msg);
send(sockfd,msg,sizeof(msg),0);
recv(sockfd,msg1,sizeof(msg1),0);
printf("\n%s",msg1);
close(sockfd);
}

