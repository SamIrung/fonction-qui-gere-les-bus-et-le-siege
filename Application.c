#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//INFO SUR SEJ-TRANS
void A_propos()
{
    printf("\tSEJ-TRANS\n");
    printf("\t==========\n");
    printf("SEJ-TRANS est une entreprise de tansport tres fiable et ......\n");
}
//verification dans la base
int Veification()
{
    char recherche[50];
    char ligne[10000];
    int trouve = 0;
    int position = 0;

    printf("Entrez un identifiant : ");
    scanf("%s", recherche);

    FILE *fichier = fopen("reservations.txt", "r");  // Ouvre le fichier en mode lire
    if (fichier == NULL)
    {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return 1;
    }
    while (fgets(ligne, sizeof(ligne), fichier))
    {
        position++;
        if(strstr(ligne, recherche)!= NULL)
        {
            trouve=1;

            printf("le nom existe dans les reservation, position %d \n\n", position);
            printf("\n _____________________________________________________________________________________________________________________________________\n");
            printf("\n| %s|", ligne);
            printf("\n --------------------------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    if (!trouve)
    {
        printf("\n ___________________________________________\n");
        printf("\n| %s n'est pas trouvE dans les reservations |\n", recherche);
        printf("\n -------------------------------------------\n");
    }
    fclose(fichier);
    return 0;

}
int Annuler()
{
    exit(0);//fonction pour quitter le programme
    return 0;
}

//Jonathan
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
int Info_Client()
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

//Spiro
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
int Destination()
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
            Annuler();
            break;
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
            Annuler();
            break;
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

//SamIrung
//SIEGE QUE LE CLIENT VEUT RESERVER
#define Nb_Bus 2
#define Nb_Siege_par_bus 5
#define Nb_SECTIONS 3

// Structure pour représenter un siège dans un bus
typedef struct
{
    int occuper;
    int section;  // 0 = avant, 1 = milieu, 2 = arrière
} Siege;

// Structure pour représenter un bus
typedef struct
{
    char code[4];
    Siege seats[Nb_Siege_par_bus];
} Bus;

// Fonction pour trouver un bus avec des sièges libres
int bus_libre(Bus buses[])
{
    for (int i = 0; i < Nb_Bus; i++)
    {
        for (int j = 0; j < Nb_Siege_par_bus; j++)
        {
            if (!buses[i].seats[j].occuper)
            {
                return i;
            }
        }
    }
    return -1;
}

// Fonction pour réserver un siège dans un bus
int reserver_siege(Bus buses[], int bus_index, int section)
{
    for (int i = 0; i < Nb_Siege_par_bus; i++)
    {
        if (!buses[bus_index].seats[i].occuper && buses[bus_index].seats[i].section == section)
        {
            buses[bus_index].seats[i].occuper = 1;
            return 1;
        }
    }
    return 0;
}

// Fonction pour afficher les réservations
void afficher_reservation(Bus buses[])
{
    printf("Reservations :\n");
    for (int i = 0; i < Nb_Bus; i++)
    {
        for (int j = 0; j < Nb_Siege_par_bus; j++)
        {
            if (buses[i].seats[j].occuper)
            {
                printf("Vous etes dans le Bus %s, a la section %d\n", buses[i].code, buses[i].seats[j].section);
            }
        }
    }
}
// Fonction pour écrire les réservations dans un fichier
void ecrire_fichier(Bus buses[])
{
    FILE* fichier=NULL;
    fichier = fopen("reservations.txt", "a");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    for (int i = 0; i < Nb_Bus; i++)
    {
        for (int j = 0; j < Nb_Siege_par_bus; j++)
        {
            if (buses[i].seats[j].occuper)
            {
                fprintf(fichier, "Bus %s, section %d, ", buses[i].code, buses[i].seats[j].section);
            }
        }
    }

    fclose(fichier);
}
//FONCTION PPRINCIPALE QUI GERE LES SIEGES ET LES BUS
int Siege_disponible()
{
    Bus buses[Nb_Bus];

    // Initialisation des bus avec des sièges libres
    for (int i = 0; i < Nb_Bus; i++)
    {
        sprintf(buses[i].code, "%03d", i + 1);
        for (int j = 0; j < Nb_Siege_par_bus; j++)
        {
            buses[i].seats[j].occuper = 0;
            buses[i].seats[j].section = j % Nb_SECTIONS;
        }
    }
    // gérer les réservations
    int bus_index = bus_libre(buses);
    if (bus_index == -1)
    {
        printf("Desole, tous les bus sont complets pour aujourd'hui.\n");
    }
    int section;
    do
    {
        //Interraction avec l'utilisateur

        printf("\nOu voulez-vous vous asseoir ?\n0. en avant\n1. au milieu\n2. en arriere\n3. Quitter\n>> ");

        scanf("%d", &section);
        if (section == 3)
        {

            Annuler();
        }


        else if(section == 0 || section == 1 || section == 2)
        {
            break;
        }
    }
    while(1);

    if (reserver_siege(buses, bus_index, section))
    {
        printf("\nVous etes dans le bus %s.\n", buses[bus_index].code);
        //appel a la fonction pour ecrire dans fichier
        ecrire_fichier(buses);
    }
    else
    {
        printf("Desole, il n'y a plus de sieges libres a cette section. Veuillez essayer une autre section.\n");
    }

    //afficher_reservation(buses);


    return 0;
}

//Exaucer
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
int Paiement()
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
            Annuler();
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
                Annuler();
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

