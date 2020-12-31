#include <gtk/gtk.h>


void
on_buttonAfficher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttontype_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_retouraff_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
