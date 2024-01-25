#include<stdio.h>
main()
{
  int ch;
  for(ch=1;ch<=255;ch++)
   {
     if(ch%4==0)
	printf("\n");
     printf("%d -- %c \t",ch,ch);
   }
}

