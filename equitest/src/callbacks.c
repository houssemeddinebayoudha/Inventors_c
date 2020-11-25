#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout;
windowajout=create_ajout();
gtk_widget_show(windowajout);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier;
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdelete;
windowdelete=create_delete();
gtk_widget_show(windowdelete);
}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsearch;
windowsearch=create_search();
gtk_widget_show(windowsearch);
}


void
on_button6_clicked                     (GtkButton       *button,
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
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_trouver_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

