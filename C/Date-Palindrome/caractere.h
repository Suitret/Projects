#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caractere(char *tab,int nombre)					//transforme le "nombre" en caractères dans "tab"
{
	int i,j,n=1,taille=strlen(tab),*p;
	
	p = (int*)malloc(taille*sizeof(int));				//tableau pour stocker chaque chiffre du "nombre"
	
	if(p==NULL)
	exit(0);
	
	for(i=taille-1;i>=0;i--)							//stocker les restes suivant les puissances de 10
	{
		n*=10;
		*(p+i) = nombre % n;
	}
	
	n=1;
	for(i=taille-1;i>=0;i--)							//obtenir chaque chiffre de "nombre"
	{
		*(p+i) /= n;
		n *= 10;
	}	
	
	for(i=0;i<taille;i++)								// chiffre_ascii = chiffre + 48
	*(tab+i) = *(p+i)+48;
	
	free(p);
	
	return tab;
}
