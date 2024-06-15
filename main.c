#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//LA DESTINATION EST LA DATE DU VOYAGE

typedef struct
{
    int jour;
    int mois;
    int heure;
    int annee;
    char destination[50];
} Voyage;
//fonctiion pour ecrire dans le fichier
void ecrireDansFichier(Voyage v)
{
    FILE *f = fopen("reservations.txt", "a");
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(f, "Destination: %s, ", v.destination);
    fprintf(f, "Date: %d/%d/%d, ", v.jour, v.mois, v.annee);
    fprintf(f, "Heure: %dh00', ", v.heure);
    fclose(f);
}
//fonction principale qui gere  la destinattion et la date
int main()
{
    Voyage v;
    int choix;
    do
    {

        printf("\nChoisissez votre destination:\n1. Kasumbalesa\n2. Kipushi\n3. Likasi\n4. Kolwezi\n5. Quitter\n>> ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1:
            strcpy(v.destination, "Kasumbalesa");
            break;
        case 2:
            strcpy(v.destination, "Kipushi");
            break;
        case 3:
            strcpy(v.destination, "Likasi");
            break;
        case 4:
            strcpy(v.destination, "Kolwezi");
            break;
        case 5:
            //Annuler();
            //break;
            exit(0);
        default:
            printf("Choix invalide.\n");
            continue;
        }
        if(choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5)
        {
            break;
        }
    }
    while(1);

    printf("Entrez le jour du voyage: ");
    scanf("%d", &(v.jour));
    printf("Entrez le mois du voyage: ");
    scanf("%d", &(v.mois));
    do
    {
        printf("Choisissez l'heure d'embarquement :\n1. 9h\n2. 12h\n3. 15h\n4. Quitter\n>> ");
        scanf("%d", &choix);
        switch(choix)
        {
        case 1:
            v.heure = 9;
            break;
        case 2:
            v.heure = 12;
            break;
        case 3:
            v.heure = 15;
            break;
        case 4:
            //Annuler();
           // break;
           exit(0);
        default:
            printf("Choix invalide.\n");
            return 0;
        }

        if(choix == 1 || choix == 2 || choix == 3 || choix == 4)
        {
            break;
        }
    }
    while(1);

    //Genere automatiique l'année actuelle
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    v.annee = tm.tm_year + 1900;
    //Appel a la foncion, pour ecrire dans le fichier
    ecrireDansFichier(v);
    return 0;
}
