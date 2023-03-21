#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estPalindrome(char *date)						//révèle si une chaine de caractères est un palindrome ou pas
{
	int i,taille = strlen(date);	
	char *p,*pt,*temp1;
	int *temp2;
	
	temp1 = (char*)malloc(taille*sizeof(char));		//chaine temporaire pour stocker la date
	temp2 = (int*)malloc((taille-2)*sizeof(int));	//chaine pour tester la symétrie de la date
	
	if(temp1==NULL ||temp2==NULL)
	exit(0);
	
	for(i=0;i<taille;i++)							//copie de date dans temp1
	*(temp1+i) = *(date+i);
	
	p=strchr(temp1,'-');
	do												//suppression des caractères "-" dans temp1
	{
		taille = strlen(temp1);
		for(pt=p;pt<temp1+taille;pt++)
		{
			*(pt) =*(pt+1);
		}
		
		p=strchr(temp1,'-');
	}	while(p!=NULL);
	
	taille = strlen(temp1);
	
	for(i=0;i<taille;i++)							//remplissage de temp2 sans '\0'
	{
		*(temp2+i) = *(temp1+i);
	}
	
	
	for(i=0;i<taille/2;i++)						//test de symétrie de temp2
	{
		if(*(temp2+i) != *(temp2+taille-1-i))		
		{	
			free(temp1);
			free(temp2);
			return 0;
		} 
	}
	
	free(temp1);
	free(temp2);
	
	return 1;
}

