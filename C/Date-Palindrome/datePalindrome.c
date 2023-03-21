#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estBissextile.h"
#include "dateCorrecte.h"
#include "decimal.h"
#include "estPalindrome.h"
#include "caractere.h"
#include "modifie.h"

int main()
{
	int jour,mois,annee,i;
	char date[11],*p,test;
	
	system("clear");
	printf("=====PROCHAINE DATE PALINDROME=====\n");
	
	do
	{
		printf("\nDonnez une date sous le format JJ-MM-AAAA\n> ");
		fgets(date,11,stdin);
		
		p = strchr(date,'\n');	
						
		if(strlen(date)==10 && p==NULL)
		while(getchar()!='\n');
		
		else
		strcpy(p,"\0");
	
		if(dateCorrecte(date) == 0)
		printf("\nVous avez entré une date incorrecte.\n");
	
		else
		{		
			jour = decimal(date,date+1);
			mois = decimal(date+3,date+4);
			annee = decimal(date+6,date+9);
		
			if(jour == 0 || jour>31)
			printf("Jour incorrect !\n");
		
			else if(mois == 0 || mois>12)
			printf("Mois incorrect !\n");
		
			else if((jour==31) && (mois==4 || mois==6|| mois==9|| mois==11))
			printf("Pas de %d pour ce mois !\n",jour);
		
			else if((jour==30 || jour==31) && mois==2)
			printf("Février ne comporte jamais %d jours !\n",jour);
		
			else if(jour == 29 && mois == 2 && estBissextile(annee) == 0)
			printf("L'année %d n'est pas bissextile !\n",annee);
		
			else
			{
				printf("Date correcte.\n");
				
				while(estPalindrome(date) == 0)
				{
					modifie(date,&jour,&mois,&annee);
				}
				
				printf("=======================\n");
				printf("%s\n",date);
				printf("=======================\n");								
			}
		}

		printf("\nRecommencer ? (o/n)\n> ");
		scanf("%c",&test);
		while(getchar()!='\n');
	
	}	while(test!='n' && test!='N');
	
	return 0;
}
