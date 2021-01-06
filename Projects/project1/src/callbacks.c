#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include<string.h>
#include<stdio.h>


void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *nom,*sortie;
char x[10];
nom=lookup_widget(button,"entry1");
sortie=lookup_widget(button,"label1");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(nom)));
gtk_label_set_text(GTK_LABEL(sortie),x);







}

