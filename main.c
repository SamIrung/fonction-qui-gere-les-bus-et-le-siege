#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//INFORMATION SUR LE CLIENT

struct Reservation
{
    char nom[50];
    char postnom[50];
    char telephone[15];
    int destination;
    int numero;
};

//fonction pour gener le code du client
int genererNumeroReservation()
{
    return 1000 + rand() % 9000;  // Génère un numéro aléatoire entre 1000 et 9999
}
//fonction pour enregiisre dans le fichier les infos du clientt
void enregistrerReservation(struct Reservation res)
{
    FILE *fichier = fopen("reservations.txt", "a");  // Ouvre le fichier en mode ajout
    if (fichier == NULL)
    {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return;
    }
    else if(fichier != NULL)
    {
        fprintf(fichier, "\nNom: %s - %s, ", res.nom, res.postnom);
        fprintf(fichier, "Téléphone: %s, ", res.telephone);
        fprintf(fichier, "Code: %d, ", res.numero);
    }
    fclose(fichier);  // Ferme le fichier
    printf("Voici Code de reservation: %d\n", res.numero);
}
//la fonction princiale qui gere les information du client
int main()
{
    struct Reservation reservations[10];
    int nbReservations = 0;

    srand(time(0));  // Initialisation du générateur de nombres aléatoires

    char nom[50];
    char postnom[50];
    char telephone[15];
    int destination;

    printf("\nVeillez Entrer ces informations pour la reservation\n");
    printf("--------------------------------------------------\n");
    printf("votre prenom : ");
    scanf("%s", nom);
    printf("votre nom : ");
    scanf("%s", postnom);
    printf("votre numero de telephone : ");
    scanf("%s", telephone);

    reservations[nbReservations].numero = genererNumeroReservation();
    strcpy(reservations[nbReservations].nom, nom);
    strcpy(reservations[nbReservations].postnom, postnom);
    strcpy(reservations[nbReservations].telephone, telephone);

    enregistrerReservation(reservations[nbReservations]);  // Enregistre la réservation dans le fichier

    nbReservations++;
    return 0;
}
