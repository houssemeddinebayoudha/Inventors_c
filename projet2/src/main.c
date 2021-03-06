/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *plantation_v__g__tale;
  GtkWidget *fenetre_ajout;
  GtkWidget *fenetre_affcihe_;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  plantation_v__g__tale = create_plantation_v__g__tale ();
  gtk_widget_show (plantation_v__g__tale);
  fenetre_ajout = create_fenetre_ajout ();
  gtk_widget_show (fenetre_ajout);
  fenetre_affcihe_ = create_fenetre_affcihe_ ();
  gtk_widget_show (fenetre_affcihe_);

  gtk_main ();
  return 0;
}

