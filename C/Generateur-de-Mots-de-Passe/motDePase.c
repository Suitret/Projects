#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int taille,i;
	char test,*motDePasse;
	srand(time(NULL));
	system("clear");
	
	printf("=====GÉNÉRATEUR DE MOTS DE PASSE=====\n");
	
	do
	{
		do
		{
			printf("\nTaille du mot de passe\n> ");
			scanf("%d",&taille);
			while(getchar()!='\n');
		}	while(taille<=0);
		
		motDePasse=(char*)malloc(taille*sizeof(char));
		
		if(motDePasse==NULL)
		exit(0);
		
		for(i=0;i<taille;i++)
		{
			*(motDePasse + i)= (rand()%74) + 48;
		}
		
		printf("=========================================\n");
		printf("%s\n",motDePasse);
		printf("=========================================\n");
		
		free(motDePasse);
		
		printf("Recommencer ?\n> ");
		scanf("%c",&test);
		while(getchar()!='\n');
		
	}	while(test!='n' && test!='N');
	
	return 0;
}
