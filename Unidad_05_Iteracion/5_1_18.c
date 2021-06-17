#include <stdio.h>

void main ()
{
   int tabla,num;

   for (tabla =1;tabla<10;tabla++)
   {
   	printf("\n");

   	for (num =1;num<10;num++)
        printf("%3d", tabla*num);

   }
	getch();
}
