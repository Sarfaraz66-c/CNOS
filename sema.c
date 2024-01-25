#include<stdio.h>
#include<unistd.h>
main()
{
	int p[2];
	char b[10]="more moye",b1[10];
	pipe(p);
	
	write(p[1],b,10);
	
	read(p[0],b1,10);

	close(p[1]);
	
	close(p[0]);

	printf("after reading from pipe b1 is %s\n",b1);

	
}
