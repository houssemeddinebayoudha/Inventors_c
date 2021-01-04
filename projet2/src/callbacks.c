#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plantation.h"


void
on_Ajouter_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
 
}




void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
plantation P;
char qte[20];
GtkWidget *input1, *input2, *input3, *input4 , *input5;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

input1=lookup_widget(objet,"type");
input2=lookup_widget(objet,"saison");
input3=lookup_widget(objet,"quantite");

strcpy(P.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(P.saison,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(qte,gtk_entry_get_text(GTK_ENTRY(input3)));
P.quantite=atoi(qte);
ajouter_plante(P);

}



void
on_afficher_clicked                    (GtkTreeView       *treeview,
                                        gpointer         user_data)
{
/*

GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(GObject,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(GObject,"fenetre_afficher");
fenetre_affiche=create_fenetre_affiche_();

gtk_widget_show(fenetre_affiche);

treeview1=lookup_widget(fenetre_affiche,"treeview1");

afficher_plante(treeview1);
*/
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                       GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                       gpointer         user_data)
{
/*
GtkTreeIter iter;
gchar* type;
gchar* saison;
gchar* quantite; 
plantation *P;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path))
{

	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&type,1,&saison,2,&quantite,-1);
	strcpy(P->type,type);
	strcpy(P->saison,saison);
	strcpy(P->quantite,quantite);
}
	supprimer_plante(*P);
	afficher_plante(treeview);
*/}

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer__clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void 
on_chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}




void 
on_supprime_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}


/*void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

}*/


