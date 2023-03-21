#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimal(char *p1,char *p2)					//convertit en décimal un nombre stocké dans un tableau de CHAR
{
	int n=1,conv=0;
	char *p;
	
	for(p=p2;p>=p1;p--)
	{
		conv+=(*(p)-48)*n;						//chiffre = chiffre_ascii - 48
		n*=10;		
	}
	return conv;
}
