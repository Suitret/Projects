#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dateCorrecte(char *date)					//s'assure que la chaine ne contient que des chiffres et deux tirets
{
	int i;
	if(strlen(date)==10 && *(date+2)=='-' && *(date+5)=='-')	//taille = 10 et contient deux tirets
	{
		for(i=0;i<2;i++)
		{
			if(*(date+i)<48 || *(date+i)>57)	//s'assure que la chaine ne contient que des chiffres pour le jour
			return 0;
		}
		
		for(i=3;i<5;i++)						//s'assure que la chaine ne contient que des chiffres pour le mois
		{
			if(*(date+i)<48 || *(date+i)>57)
			return 0;
		}
		
		for(i=6;i<10;i++)						//s'assure que la chaine ne contient que des chiffres pour l'année
		{
			if(*(date+i)<48 || *(date+i)>57)
			return 0;
		}
		
		return 1;
	}
	
	else
	return 0;
}
