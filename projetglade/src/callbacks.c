#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
char temp[20]="brebi";
char tempmodif[20]="brebi";
char sexemodif[20]="male";
char typpe[20]="brebi";
void
on_buttonAfficher_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
   GtkWidget *Mestroupeaux;
   GtkWidget *affiche;
   GtkWidget *treeview1;

Mestroupeaux=lookup_widget(objet, "Mestroupeaux");

gtk_widget_destroy(Mestroupeaux);

affiche=create_afficher();

gtk_widget_show(affiche);

treeview1=lookup_widget(affiche,"treeview1");
 afficher(treeview1);

}


void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
 GtkWidget *Mestroupeaux, *Ajouterunanimal;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);
Ajouterunanimal=create_Ajouterunanimal();
gtk_widget_show(Ajouterunanimal);


}


void
on_buttonModifier_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux, *modifier;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);

modifier=create_modifier();
gtk_widget_show(modifier);

}


void
on_buttontype_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux, *type;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);

type=create_type();
gtk_widget_show(type);

}


void
on_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*Ajouterunanimal;
Ajouterunanimal=lookup_widget(objet,"Ajouterunanimal");
gtk_widget_destroy(Ajouterunanimal);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}

void
on_retouraff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)

{ 
GtkWidget *Mestroupeaux,*afficher;
afficher=lookup_widget(objet,"afficher");
gtk_widget_destroy(afficher);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}
void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ 	
	GtkWidget *id;
	GtkWidget *Jour;
	GtkWidget *Mois;
	GtkWidget *Annee;
	GtkWidget *Combobox1;
	GtkWidget *Ajouterunanimal;

animal a;
 Ajouterunanimal=lookup_widget(objet, "Ajouterunanimal");
 id=lookup_widget(objet, "id");
 Jour=lookup_widget(objet,"Jour");
 Mois=lookup_widget(objet,"Mois");
 Annee=lookup_widget(objet,"Annee");
 Combobox1=lookup_widget(objet,"combobox1");
 

 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id)));
 a.date_naiss.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
 a.date_naiss.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
 a.date_naiss.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
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





void
on_retourmodif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*modifier;
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);

}


void
on_buttonmodifier_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *id;
	GtkWidget *id1;
	GtkWidget *Jour;
	GtkWidget *Mois;
	GtkWidget *Annee;
	GtkWidget *Combobox2;
	GtkWidget *modifier;
animal a;
char idd[10];
modifier =lookup_widget(objet, "modifier" );
 id=lookup_widget(objet, "id");	
 id1=lookup_widget(objet, "id1");
 Jour=lookup_widget(objet,"Jour");
 Mois=lookup_widget(objet,"Mois");
 Annee=lookup_widget(objet,"Annee");
Combobox2=lookup_widget(objet,"combobox2");
 
 

 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id1)));
 a.date_naiss.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
 a.date_naiss.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
 a.date_naiss.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));
 strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
 strcpy(a.sexe,sexemodif);

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
modifie(idd,a);
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(sexemodif,"male");
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(sexemodif,"femelle");
}





void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(typpe,"veau");
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(typpe,"Brebi");
}




void
on_OK_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *OK;
animal a;
OK =lookup_widget(objet, "OK" );
 strcpy(a.type,typpe);
}


void
on_retourtype_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*type;
type=lookup_widget(objet,"type");
gtk_widget_destroy(type);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}

