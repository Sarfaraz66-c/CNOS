// CONNECTION ORIENTED CONCURRENT DATE AND TIME (CLIENT)

 #include<stdio.h> 
 #include<stdlib.h>
 #include<unistd.h>
 #include<sys/types.h>
 #include<sys/socket.h>
 #include<netinet/in.h>
 #include<arpa/inet.h>
 main()
 {
  int sockfd,j;
  struct sockaddr_in sa;
  char msg1[30],msg2[30];
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  if(sockfd<0)
  { 
    perror("Socket not created");
    exit(0);
  }
  sa.sin_family=AF_INET;
  sa.sin_port=htons(6100);
  sa.sin_addr.s_addr=inet_addr("127.0.0.1");
  j=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));
  if(j<0)
  {
    perror("connection not created\n");
    exit(0);
  }
  //printf("\nEnter a message: ");
  //scanf("%s",msg1);
  //send(sockfd,msg1,sizeof(msg1),0);
  recv(sockfd,msg2,sizeof(msg2),0);
  printf("Date is: %s\n",msg2);
  close(sockfd);
 } 

