#include<unistd.h>
  #include<stdio.h>
  #include<sys/types.h>
  #include<sys/msg.h>
   #include<string.h>

  struct msgbuf
 {
   long mtype;

   char mtext[50];

  } m1,m2;

  main()

 {

   int msqid,pid;
    
    msqid=msgget((key_t)67,IPC_CREAT | 0666);

    pid=fork();

   if(pid==0)

   {
       printf("Child Process\n");

       m1.mtype=1;
       strcpy(m1.mtext,"hello");

      msgsnd(msqid,(struct msgbuf *)&m1,sizeof(m1),0);
	sleep(5);
      printf(" In Child process again \n");

       msgrcv(msqid,(struct msgbuf *)&m2,sizeof(m2),1,0);

      printf("msg recvd from parent in child process is %s \n",m2.mtext);

    }

  else

  {
 
      printf("ParentProcess\n");
      msgrcv(msqid,(struct msgbuf *)&m2,sizeof(m2),1,0);
	printf("Msg recevied from child in parent process is %s\n",m2.mtext);
	msgsnd(msqid,(struct msgbuf*)&m2,sizeof(m2),0);
}
}

