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
EDATE,
COLUMNS
};

enum{
EMOIS,
ETAUX,
TESTS
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

void modifier(char id[],char etat,int dispo);

void supprimer(char id[20]);

equi chercher(char id[20]);

void afficher(GtkWidget *liste);

void tauxdabs(int annee,int nbr,GtkWidget *treeview);

void marquer_abse(int id,int jour,int mois,int annee,int abs);

