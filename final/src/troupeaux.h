#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<gtk/gtk.h>
enum
{
EIDD,
ETYPEE,
ESEXEE,
EDATEE,
TROU,
};
typedef struct {
  int jour;
  int mois;
  int annee;
   }date; 
typedef struct {
  char id[10];
  char type[20];
  char sexe[20];
  date date_naiss;
   }animal;
 void ajout(animal a);
 void modifie(char id[10], animal a);
 void supprimerr (char id [10]);
 void affficher(GtkWidget *liste);
 int nbr_de_trp_chaq_type( char type[20]);
