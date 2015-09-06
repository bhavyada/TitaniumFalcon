/*
 ============================================================================
 Name        : Union_example.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	typedef union
	{
		int a;
		char b[10];
		float c;
	}
	Union;

	Union x,y = {100};
	x.a = 500;
	strcpy(x.b,"hello");
	x.c = 21.50;
	printf("Union x : int = %d   char = %s float = %f n\n",x.a,x.b,x.c);
	printf("Union y : int = %d   char = %s float = %f n\n",y.a,y.b,y.c);
	return 0;

}

