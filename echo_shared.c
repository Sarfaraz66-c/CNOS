#include<unistd.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
   main()
 {
   int p1[2],p2[2],pid;
   char m1[10]="welcome",m2[10],m3[10]="oslab",m4[10];
   pipe(p1);
   pipe(p2);

   pid=fork();
   if(pid==0)
   {
   	printf("\n Child Process started\n");
	printf("Child writing message using pipe  that is--->%s\n",m1);
   	close(p1[0]);
   	close(p2[1]);
   	write(p1[1],m1,sizeof(m1));
   	sleep(5);
   	read(p2[0],m4,sizeof(m4));
   	printf("CP reading message from parent using pipe  that is --->%s\n",m4);
  	 close(p2[0]);
   	close(p1[1]);
  }

  else
 {
   printf("Parent process started\n");
  close(p1[1]);
   close(p2[0]);
   read(p1[0],m2,sizeof(m2));
	printf("Parent Reading msg from child using pipe that is--->  %s\n",m2);
   write(p2[1],m3,sizeof(m3));
	printf("Parent writing message using pipe that is---> %s\n",m3);

  }
 }

