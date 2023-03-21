#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nombre_aleatoire(int taille, int premier)
{
    return (rand()%taille) + premier;
}

int main ()
{
    int nbP = 0, nbM = 0, tM = 0, i, j, k, val;
    srand(time(NULL));

    do
    {
        printf("Nombre de paragraphes: ");
        scanf("%d", &nbP);
        printf("Nombre de mots par paragraphe: ");
        scanf("%d", &nbM);
        printf("Taille maximale des mots: ");
        scanf("%d", &tM);
    }   while((nbM <= 0) || (nbP <= 0) || (tM <= 0));

    system("clear");
    printf("\n\t\t\t==================================TEXTE ALÉATOIRE==================================\n\n");

    for(i = 0; i < nbP; i++)            //paragraphes
    {
        
        printf("%c", nombre_aleatoire(26, 65));     //caractère majuscule

        for(j = 0; j < nbM; j++)        //mots
        {
            val = nombre_aleatoire(tM+1, 1);

            for(k = 0; k < val; k++)    //caractères
            {
                printf("%c", nombre_aleatoire(26, 97));
            }

            printf(" ");
        }
        printf("\n\n");
    }
    printf("\n");
    return 0;
}