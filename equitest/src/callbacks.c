#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
char x='f';
int i=0;
char x2='f';
void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
windowajout=create_ajout();
gtk_widget_show(windowajout);
}


void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

}


void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *windowdelete;
windowdelete=create_delete();
gtk_widget_show(windowdelete);*/
}


void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *windowaff,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
GtkWidget *treeview;
windowaff=create_window1();
gtk_widget_show(windowaff);
treeview=lookup_widget(windowaff,"treeview1");
afficher(treeview);

}


void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsearch,*actual;
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
windowsearch=create_search();
gtk_widget_show(windowsearch);
}


void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*marque,*home,*actual,*jour,*mois,*annee;
char text[20];
equi e;
id=lookup_widget (button, "id");
marque=lookup_widget (button, "marque");
actual=lookup_widget (button, "ajout");
jour=lookup_widget (button, "jour");
mois=lookup_widget (button, "combobox1");
annee=lookup_widget(button, "annee");
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(marque)));

e.etat=x;
e.dispo=i;
e.date_daj.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
e.date_daj.mois=atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
e.date_daj.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
equi e1=chercher(e.id);


if((e1.dispo==10)&&(strlen(e.id)>0)){
ajouter(e);
home=create_success();
gtk_widget_destroy(actual);
gtk_widget_show(home);}
else{
home=create_failed();
gtk_widget_destroy(actual);
gtk_widget_show(home);
}
}


void
on_delete_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *id;
char idd[20];
id=lookup_widget (button,"id");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
supprimer(idd);
}


void
on_trouver_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *id,*label;
char idd[20];

id=lookup_widget (objet_graphique,"id");
label=lookup_widget (objet_graphique,"label9");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));


equi e=chercher(idd);
char aff[250];
if(e.dispo==10){
sprintf(aff,"n existe pas");
}
else
sprintf(aff,"ID %s , Marque %s , etat %c , disponiblité %d en %d/%d/%d ",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);

gtk_label_set_text(GTK_LABEL(label),aff);




}


void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *id,*etat;
char idd[20],text[20],e;
id=lookup_widget (button,"id");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));

e=x2;
modifier(idd,e);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkTreeSelection *selection;
GtkWidget p;
gchar* id;
gchar* marque;
gchar* etat;
gchar* dispo;
gchar* date;
equi e;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

selection=gtk_tree_view_get_selection(treeview);
if (gtk_tree_model_get_iter(model, &iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&marque,2,&etat,3,&dispo,4,&date, -1);
supprimer(id);
afficher(treeview);

}





}


void
on_retourner_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);
}



void
on_retourajout_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"ajout");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}


void
on_retoursearch_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual,*treeview;
actual=lookup_widget(button,"search");
gtk_widget_destroy(actual);
home=create_window1();
gtk_widget_show(home);
treeview=lookup_widget(home,"treeview1");
afficher(treeview);

}


void
on_retournermodifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual,*treeview;
actual=lookup_widget(button,"modifier");
gtk_widget_destroy(actual);
home=create_window1();
gtk_widget_show(home);
treeview=lookup_widget(home,"treeview1");
afficher(treeview);

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x='f';
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x='p';
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
i=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
i=1;
}


void
on_retoursuccess_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"success");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}


void
on_errorredo_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"failed");
gtk_widget_destroy(actual);
home=create_ajout();
gtk_widget_show(home);

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x2='f';
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x2='p';

}


void
on_sup_clicked                         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
	GtkWidget* t;

	gchar* id;

	t=lookup_widget(button,"treeview1");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(t));
if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
supprimer(id);
afficher(GTK_TREE_VIEW(t));

};



}


void
on_modif_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowmodifier,*actual,*idd;


GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
	GtkWidget* t;

	gchar* id;

	t=lookup_widget(button,"treeview1");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(t));
if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);


};
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

idd=lookup_widget(windowmodifier,"id");


gtk_entry_set_text(idd,id);

}



