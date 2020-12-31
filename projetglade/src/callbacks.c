#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
char temp[20]="brebi";


void
on_buttonAfficher_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux;
   GtkWidget *afficher;
   GtkWidget *treeview1;

Mestroupeaux=lookup_widget(objet, "Mestroupeaux");

gtk_widget_destroy(Mestroupeaux);
afficher=lookup_widget(objet, "afficher");
afficher=create_afficher();

gtk_Widget_show(afficher);

treeview1=lookup_widget(afficher,"treeview1");
 afficher(treeview1);

}


void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
 GtkWidget *Mestroupeaux, *Ajouterunanimal;
Mestroupeaux=lookup_widget(objet, " Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);
Ajouterunanimal=lookup_widget(objet, "Ajouterunanimal");
Ajouterunanimal=create_Ajouterunanimal();
gtk_widget_show(Ajouterunanimal);


}


void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttontype_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*Ajouterunanimal;
Ajouterunanimal=lookup_widget(objet,"window1");
gtk_widget_destroy(Ajouterunanimal);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}

void
on_retouraff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

{ 
GtkWidget *Mestroupeaux,*afficher;
afficher=lookup_widget(objet,"window1");
gtk_widget_destroy(afficher);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ 	
	GtkWidget *id;
	GtkWidget *Jour;
	GtkWidget *Mois;
	GtkWidget *Annee;
	GtkWidget *Combobox1;
	GtkWidget *Combobox2;

	animal a;
 id=lookup_widget(objet, "id");
 Jour=lookup_widget(objet,"Jour");
 Mois=lookup_widget(objet,"Mois");
 Annee=lookup_widget(objet,"Annee");
 combobox1=lookup_widget(objet,"Sexe");
 combobox2=lookup_widget(objet,"Type");

 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id)));
 a.date_naiss.jour=gtk_spin_button_get_value_as_int (GTK_COMBO_BOX(Jour));
 a.date_naiss.mois=gtk_spin_button_get_value_as_int (GTK_COMBO_BOX(Mois));
 a.date_naiss.annee=gtk_spin_button_get_value_as_int (GTK_COMBO_BOX(Annee));


 a.sexe= gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1);  
 strcpy(a.type,temp);
ajouter(a);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* sexe;
gchar* date;
animal a;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&sexe,3,&date, -1);
supprimer(id);
afficher(treeview1);
}
 }


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(temp,"brebi");
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(temp,"veau");

}

