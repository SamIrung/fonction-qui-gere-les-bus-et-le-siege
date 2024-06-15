#include <stdio.h>
#include <stdlib.h>

//FAIRE LE PAIMENT

// Définir le montant de la réservation et le nombre maximal de réservations
#define MONTANT_RESERVATION 25000
#define MAX_RESERVATIONS 5

// Structure pour les informations de l'opérateur
typedef struct
{
    char nom[20]; // Nom de l'opérateur
    int nombre_reservations; // Nombre de réservations effectuées
} Operateur;

// Fonction pour gérer le dépôt
void depot(Operateur *operateur, Operateur *operateurs, int taille)
{
    int nombre_nouvelles_reservations; // Variable pour stocker le nombre de nouvelles réservations
    int montant; // Variable pour stocker le montant entré par l'utilisateur

    while (1)   // Boucle pour s'assurer que le montant correct est entré
    {
        printf("\nla reservation revient a 25000fc\n");
        printf("Veuillez entrer le montant pour la reservation : ");
        scanf("%d", &montant); // Lire le montant entré par l'utilisateur
        FILE *fichier = fopen("reservations.txt", "a");  // Ouvre le fichier en mode ajout
        // Vérifier si le montant est correct
        if (montant != MONTANT_RESERVATION)
        {
            printf("Montant incorrect. Le montant doit etre de %d fc.\n", MONTANT_RESERVATION);
        }
        else
        {
            // Mettre à jour le nombre de réservations de l'opérateur
            operateur->nombre_reservations += nombre_nouvelles_reservations;
            printf("Paiement de %d fc effectue avec succes pour votre reservation.", montant);

            fprintf(fichier, "cash de: %dfc\n", montant);


            break; // Sortir de la boucle si le montant est correct
        }
        fclose(fichier);  // Ferme le fichier
    }
}


// Fonction pour gérer la vérification
void verification(Operateur *operateur)
{
    if (operateur->nombre_reservations > 0)
    {
        // Afficher le nombre de réservations pour l'opérateur
        printf("Vous avez %d reservation(s) via %s.\n", operateur->nombre_reservations, operateur->nom);
    }
    else
    {
        // Afficher un message si aucune réservation n'a été trouvée
        printf("Aucune reservation trouvee.\n");
    }
}

//  fonction principale qui gere le paiement
int main()
{
    int choix; // Variable pour stocker le choix de l'utilisateur
    int operateur_choix; // Variable pour stocker le choix de l'opérateur
    char retour; // Variable pour stocker le choix de retour de l'utilisateur

    // Initialiser les opérateurs
    Operateur operateurs[4] =
    {
        {"Orangemoney", 0},
        {"Afrimoney", 0},
        {"Airtelmoney", 0},
        {"Mpesa", 0}
    };
    do
    {
        printf("\nVeuillez choisir votre operateur:\n");
        printf("1. Orangemoney\n"); // Option pour Orangemoney
        printf("2. Afrimoney\n"); // Option pour Afrimoney
        printf("3. Airtelmoney\n"); // Option pour Airtelmoney
        printf("4. Mpesa\n"); // Option pour Mpesa
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &operateur_choix); // Lire le choix de l'utilisateur

        if (operateur_choix == 5)
        {
            //Annuler();
            exit(0);
        }
        else if(operateur_choix == 1 || operateur_choix == 2 || operateur_choix == 3 || operateur_choix == 4)
        {
            break;
        }
    }
    while(1);

    if (operateur_choix >= 1 && operateur_choix <= 4)   // Vérifier si le choix est valide
    {
        Operateur *operateur = &operateurs[operateur_choix - 1];

        // Fonction pour afficher le menu principal
        do
        {
            printf("\n1. effectuer la reservaton\n"); // Option pour le dépôt
            printf("2. Verification de la reservation\n"); // Option pour la vérification
            printf("3. Quitter\n");
            printf("Entrez votre choix: ");
            scanf("%d", &choix); // Lire le choix de l'utilisateur

            switch (choix)
            {
            case 1:
                depot(operateur, operateurs, 4); // Appeler la fonction dépôt
                break;
            case 2:
                verification(operateur); // Appeler la fonction vérification
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
            }

            if (choix == 3)
            {
                //Annuler();
                exit(0);
            }
            else if(choix == 1 || choix == 2)
            {
                break;
            }
        }
        while(1);
    }
    else
    {
        printf("Choix invalide. Veuillez reessayer.\n");
    }

    return 0;
}
