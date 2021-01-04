#include<gtk/gtk.h>

typedef struct
{
char type[30];
char saison[30];
int quantite;
}plantation;



enum 
{
	ETYPE,
	ESAISON,
	EQUANTITE,
	COLUMNS
};



void ajouter_plante(plantation P);
void afficher_plante(GtkTreeView *liste);
void supprimer_plante(plantation P );
