#include <stdio.h>
#include <stdlib.h>

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
int main()
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

            //Annuler();
            exit(0);
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
