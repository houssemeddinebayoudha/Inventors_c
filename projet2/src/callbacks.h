#include <gtk/gtk.h>


void
on_Ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_afficher_clicked                    (GtkTreeView       *treeview,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer__clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprime_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);
