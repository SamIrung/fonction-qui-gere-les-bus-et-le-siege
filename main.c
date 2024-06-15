#include <stdio.h>
#include <stdlib.h>
#include "Application.h"
int main()
{
    int choix_principal;
    printf("\t\tBIENVENUE CHEZ SEJ-TRANS \n");
    printf("\t\t===========================\n\n");

    do
    {
        printf("\t\t1.FAIRE UNE RESERVATION\n\t\t2.VERIFIER SI J'AI UNE RESERVATION\n\t\t3.INFO SUR SEJ-TRANS\n>> ");
        scanf("%d", &choix_principal);
        switch(choix_principal)
        {
        case 1:    //appel aux fonctions
            Info_Client();
            Destination();
            Siege_disponible();
            Paiement();

            int reponse;
            printf("\n\nvoulez-vous faire une autre reservation\n0. NON\n1. OUI\n>> ");
            scanf("%d", &reponse);
            while(1)//boucle pour demander a l'utilisateur veut faire une autre reservation
            {
                switch(reponse)
                {
                case 1:
                    Info_Client();
                    Destination();
                    Siege_disponible();
                    Paiement();
                    printf("\n\nvoulez-vous faire une autre reservation\n0. NON\n1. OUI\n>> ");
                    scanf("%d", &reponse);
                    break;
                case 0:
                    printf("Reservation fait avec succes!");
                    exit(0);
                default:
                    printf("mauvaise saisi ,");
                    printf("\n\nvoulez-vous faire une autre reservation\n0. NON\n1. OUI\n>> ");
                    scanf("%d", &reponse);
                    continue;
                }
            }
            break;
        case 2:
            Veification();
            exit(0);
        case 3:
            A_propos() ;
            exit(0);
        default:
            printf("Erreur de saisie!\n");
            continue;
        }
    }
    while(1);
    return 0;
}
