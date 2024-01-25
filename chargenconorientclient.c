// ITERATIVE CONNECIIONLESS CLIENT PROG FOR CHARACTER GENERATION

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
main()
{
int i,sockfd,servlen;
char buff1[300],buff2[300];
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
//printf("enter a message: ");
//scanf("%s",buff1);
sendto(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&sa,sizeof(sa));
servlen=sizeof(sa);
recvfrom(sockfd,buff2,sizeof(buff2),0,(struct sockaddr*)&sa,&servlen);
printf("message is %s",buff2);
for(i=0;buff2[i]!='\0';i++)
{
  if(i%5==0)
	printf("\n");
  printf("%d --> %c \t",buff2[i],buff2[i]);
 }
}

