#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
enum{
EID,
EMARQUE,
EETAT,
EDISPO,
COLUMNS,
EDATE
};
struct Date{
int jour;
int mois;
int annee;
};

typedef struct equipementsagr{
char id[20];
char marque[20];
char etat;
int dispo;//1 si dispo 
struct Date date_daj;
}equi;


void ajouter(equi e);

void modifier(char id[],char etat);

void supprimer(char id[20]);

equi chercher(char id[20]);

void afficher(GtkWidget *liste);


//float tauxdab(struct ouvriers o);
