#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

  main()
{

 char msg1[30],msg[30];

 int sockfd=socket(AF_INET,SOCK_STREAM,0);

 struct sockaddr_in ser;

  ser.sin_family=AF_INET;

  ser.sin_port=htons(8000);

  ser.sin_addr.s_addr=inet_addr("127.0.0.1");
 
  connect(sockfd,(struct sockaddr *)&ser,sizeof(ser));
 
   printf("enter a string\n");
   scanf("%s",msg);
   send(sockfd,msg,30,0);
   //printf("Sended string \n");
   recv(sockfd,msg1,30,0);

   printf("echoed string is %s \n", msg1);

  close(sockfd);

 }


 
