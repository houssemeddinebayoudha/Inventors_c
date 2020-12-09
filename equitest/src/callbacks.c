#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout;
windowajout=create_ajout();
gtk_widget_show(windowajout);
}


void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier;
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

}


void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdelete;
windowdelete=create_delete();
gtk_widget_show(windowdelete);
}


void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *windowaff;
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
GtkWidget *windowsearch;
windowsearch=create_search();
gtk_widget_show(windowsearch);
}


void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*marque,*etat,*dispo,*home;
char text[20];
equi e;
id=lookup_widget (button, "id");
marque=lookup_widget (button, "marque");

etat=lookup_widget (button, "etat");
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(text,gtk_entry_get_text(GTK_ENTRY(etat)));
e.etat=text[0];
ajouter(e);
home=create_home();
gtk_widget_show(home);
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
etat=lookup_widget (button,"etat");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(text,gtk_entry_get_text(GTK_ENTRY(etat)));
e=text[0];
modifier(idd,e);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* marque;
gchar* etat;
gchar* dispo;
equi e;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&marque,2,&etat,3,&dispo,-1);
supprimer(id);

}





}

