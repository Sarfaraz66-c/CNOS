#include<stdio.h>
#include<fcntl.h>
main(int argc ,char *argv[])
{
int fd,fd1,n;
char buff[3];
fd=open(argv[1],O_RDONLY);
fd1=open(argv[2],O_CREAT|O_WRONLY,0600);
if(fd<0||fd1<0)
{
printf("problem with opeing fd of one of the file\n");
//exit(0);
}
/*if(fd1<0)
{
printf("problem with opeing fd1 of one of the file\n");
exit(0);
}*/
while(1)
{
n=read(fd,buff,1);
if(n<=0)
break;
write(fd1,buff,1);
}
close(fd);
close(fd1);
}
