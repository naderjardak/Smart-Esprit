/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "interface.h"
#include "support.h"



int main (int argc, char *argv[])
{

//...........
    char s;
    int a,i;
    char j[20];
    char k[20];
 //...............

  GtkWidget *n_first=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
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
  n_first = create_n_admin ();
  gtk_widget_show (n_first);
 
  gtk_init(&argc,&argv);
  
  chang_background(n_first,750,520,"B.jpg");



 


  gtk_main ();
  return 0;
}

