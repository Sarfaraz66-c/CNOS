   #include<stdio.h>
   #include<netinet/in.h>
   #include<sys/socket.h>
   int main()
   {
   struct sockaddr_in serv;
   char msg1[50], msg2[50];
   int servlen;
  int sockfd=socket(AF_INET, SOCK_DGRAM,0);

  serv.sin_family=AF_INET;
  serv.sin_addr.s_addr=inet_addr("127.0.0.1");
  serv.sin_port=htons(37);

  printf("Enter a String:");
  scanf("%s",msg1);
  servlen=sizeof(serv);
 sendto(sockfd,msg1,sizeof(msg1),0,(struct sockaddr*)&serv,sizeof(serv));
 recvfrom(sockfd, msg2,sizeof(msg2),0,(struct sockaddr*)&serv,&servlen);
  printf("Msg received from server: %s ",msg2);
  close(sockfd);
  return 0;
  }
