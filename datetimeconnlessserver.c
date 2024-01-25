// ITERATIVE CONNECTION ORIENTED SERVER CODE USING PORT NO 7

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
main()
{
int sockfd,nsockfd,j,clilen,i,k;
char msg[300];
struct sockaddr_in sa,ca;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
perror("socket not created");
exit(0);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(9014);
sa.sin_addr.s_addr=inet_addr("10.2.0.7");
j=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
if(j<0)
{
perror("bind error");
exit(0);
}
printf("%d\n",j);
listen(sockfd,5);
while(1)
{
k=0;
clilen=sizeof(ca);
nsockfd=accept(sockfd,(struct sockaddr*)&ca,&clilen);

recv(nsockfd,msg,sizeof(msg),0);
for(i=33;i<256;i++)
{
msg[k]=i;
k++;
}
msg[k]='\0';
send(nsockfd,msg,sizeof(msg),0);
printf("the message received is %s\n",msg);
close(nsockfd);
}

close(sockfd);
}

