#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifie(char *date,int *jour,int *mois,int *annee)		//modifie la date progressivement
{
	char j[3]="11",m[3]="08",a[5]="1990",*p;
	
	*jour += 1;
		
	if(*jour>31)									//jour > 31
	{
		*jour = 1;
		p = caractere(j,*jour);
		strncpy(date,p,2);
		
		*mois += 1;
				
		if(*mois>12)								//mois > 12
		{
			*mois=1;
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			*annee += 1;
			if(*annee>9999)							//annee > 9999
			{
				*annee=0;
				p = caractere(a,*annee);
				strncpy(date+6,p,4);
			}
			
			else									//annee <= 9999
			{
				p = caractere(a,*annee);
				strncpy(date+6,p,4);
			}
			
		}
		
		else										//mois <= 12
		{
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);
		}

	}
	
	
	else if(*jour==31)									//jour = 31
	{
		if(*mois==1||*mois==3||*mois==5||*mois==7||*mois==8||*mois==10||*mois==12) //Janvier,Mars,Mai,Juillet,Aout,Octobre,Décembre
		{
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);		
		}
		
		else											//Avril,Juin,Septembre,Novembre
		{
			*jour = 1;
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			*mois += 1;
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);
		}
	}
	
	else if(*jour==30)									//jour = 30
	{
		if(*mois<=12 && *mois!=2)						//valable pour tous les mois sauf Février
		{
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);			
		}
		
		else											//Février d'une année bissextile
		{
			*jour = 1;
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			*mois += 1;
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);
		}
		
	}
	
	else if(*jour==29)
	{
		if((*mois<=12 && *mois!=2) || ( *mois==2 && estBissextile(*annee) == 1)) //valable pour tous les mois si l'annee est bissextile
		{
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);			
		}
		
		else													//Février d'une année non bissextile
		{
			*jour = 1;
			p = caractere(j,*jour);
			strncpy(date,p,2);
			
			*mois += 1;
			
			p = caractere(m,*mois);
			strncpy(date+3,p,2);
			
			p = caractere(a,*annee);
			strncpy(date+6,p,4);		
		}
		
	}
	
	else															//jour <= 28
	{
		p = caractere(j,*jour);
		strncpy(date,p,2);
			
		p = caractere(m,*mois);
		strncpy(date+3,p,2);
			
		p = caractere(a,*annee);
		strncpy(date+6,p,4);
	}
	
}

