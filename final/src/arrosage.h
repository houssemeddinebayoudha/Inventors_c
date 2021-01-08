

#include <gtk/gtk.h>


typedef struct Datee
{

	int jour;
	int mois;
	int annee;
	
}Datee;

typedef struct Arrosage
{

	char id_plante[30];
	Datee dateArrosage ;
}Arrosage;


int is_empty(GtkWidget *entry) ;


void AjouterArrosage( Arrosage e) ;
void AfficherListArrosage() ;
void ModifierArrosage(Arrosage e , char ref[30]) ;
void supprimerArrosage(char ref[30]) ;
void ChercherArrosage(GtkWidget *liste, char ref[30]) ;
int anneeSeche();
int is_empty1(GtkWidget *entry) ;
int existe1(char ver[30]) ;
