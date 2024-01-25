#include<stdio.h>
 #include<sys/types.h>
 #include<sys/ipc.h>
 #include<sys/msg.h>
 #include<string.h>
 struct msgbuf
{
 long mtype;
 
 char mtext[52];
} m,m1;
 main()
{
 
 int msgqid,k,s;
 m.mtype=1;
 msgqid=msgget((key_t)67, IPC_CREAT | 0666);
 strcpy(m.mtext,"hello");
 s=msgsnd(msgqid,(struct msgbuf *)&m,sizeof(m),0);
 k=msgrcv(msgqid,(struct msgbuf *)&m1,sizeof(m1),1,0);
 printf("return val of send is %d\n", s);
 
 printf("return val of receive is %d\n", k);
 printf("msg recvd is %s\n",m1.mtext);
 }

