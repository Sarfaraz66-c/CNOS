#include<stdio.h>
   #include<netinet/in.h>
   #include<sys/socket.h>
   int main()
   {
        struct sockaddr_in serv;
        char msg1[50], msg2[50];

        int sockfd=socket(AF_INET, SOCK_STREAM,0);
        serv.sin_family=AF_INET;
        serv.sin_addr.s_addr=inet_addr("10.2.0.5");
        serv.sin_port=htons(7);

        connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
        printf("Enter a String:");
        scanf("%s",msg1);
        send(sockfd, msg1, sizeof(msg1),0);
        recv(sockfd, msg2, sizeof(msg2),0);

        printf("Msg received from server is: %s \n",msg2);
        close(sockfd);
        return 0;
  }

