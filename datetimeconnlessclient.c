// ITERATIVE CONNECTION ORIENTED CLIENT CODE USING PORT NO 7

#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<netinet/in.h>
main()
{
int sockfd,j;
struct sockaddr_in sa;
char msg[300],msg1[300];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
 perror("socket not created");
 exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(9014);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
j=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{ 
 perror("connection not created");
 exit(0);
}

send(sockfd,msg,300,0);
recv(sockfd,msg1,300,0);
printf("message is %s",msg1);
close(sockfd);
}

