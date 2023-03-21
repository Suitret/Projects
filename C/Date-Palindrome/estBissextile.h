#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estBissextile(int annee)						//annee bissextile ou pas
{
	if(annee%4 == 0 && annee%100 != 0)				//annee divisible par 4 mais pas par 100
	return 1;
	
	else if(annee%400 == 0)							//annee divisible par 400
	return 1;
	
	else
	return 0;	
}

