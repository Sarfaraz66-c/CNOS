#include<stdio.h>
  #include<sys/types.h>
  #include<sys/ipc.h>
  #include<sys/msg.h>
  #include<string.h>
  #include<stdlib.h>
  main()

 {
     int shmid,pid;

     char *ptr;
   
     shmid=shmget((key_t)87,10,IPC_CREAT | 0666);

     ptr=(char *) shmat(shmid,0,0);

      pid=fork();

     if(pid==0)
     { 
         printf("\n CP \n");
         strcpy(ptr,"CP-Welcome");
         sleep(2);
         write(1,ptr,10);
	 printf("\n");
         shmctl(ptr,IPC_RMID,0);
	 exit(0);
     }
     else
     {   
	sleep(1);
     	printf("\n PP \n");
     	write(1,ptr,10);    
	printf("\n");
     	strcpy(ptr,"PP-WELCOME");
wait(0);
//exit(0);
     }
}

