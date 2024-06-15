#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//INFO SUR SEJ-TRANS
void A_propos();
//VERIFIER SI LE NOM EST DANS LE FICHIER
int Veification();
//INFORMATION SUR LE CLIENT
struct Reservation {};
int genererNumeroReservation();
int Info_Client();

//LA DESTINATION ET LA DATE DU VOYAGE
typedef struct {} Voyage;
void ecrireDansFichier(Voyage v);
int Destination();

//SIEGE QUE LE CLIENT VEUT RESERVER
#define Nb_Bus 2
#define Nb_Siege_par_bus 5
#define Nb_SECTIONS 3
typedef struct {} Siege;
typedef struct {} Bus;
int bus_libre(Bus buses[]);
int reserver_siege(Bus buses[], int bus_index, int section, char* passenger_name);
void afficher_reservation(Bus buses[]);
void ecrire_fichier(Bus buses[]);
int Siege_disponible();

//FAIRE LE PAIEMENT
#define MONTANT_RESERVATION 25000
#define MAX_RESERVATIONS 5
typedef struct {} Operateur;
void afficherMenu();
void afficherMenuOperateurs();
void lireReservations(Operateur *operateurs, int taille);
void ecrireReservations(Operateur *operateurs, int taille);
void depot(Operateur *operateur, Operateur *operateurs, int taille);
void verification(Operateur *operateur);
void quitter();
int Paiement();

