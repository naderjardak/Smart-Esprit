#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fichier_nader.h"
#include "fonction_nader.c"

char img1[30]="B.jpg";


void chang_background(GtkWidget *widget,int w,int h,const gchar *path)
{
gtk_widget_set_app_paintable(widget,TRUE);
gtk_widget_realize(widget);
gtk_widget_queue_draw(widget);

GdkPixbuf *src_pixbuf=gdk_pixbuf_new_from_file(path,NULL);
GdkPixbuf*dst_pixbuf=gdk_pixbuf_scale_simple(src_pixbuf,w,h,GDK_INTERP_BILINEAR);

GdkPixmap *pixmap=NULL;
gdk_pixbuf_render_pixmap_and_mask(dst_pixbuf,&pixmap,NULL,128);
gdk_window_set_back_pixmap(widget->window,pixmap,FALSE);

g_object_unref(src_pixbuf);
g_object_unref(dst_pixbuf);
g_object_unref(pixmap);

}


//.....................................................................................................................................................
void
on_n_menu_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_aff ,*tree_m_aff;


m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_aff=create_n_afficher_menu();
gtk_widget_show(m_aff);

gtk_init(&argc,&argv);
chang_background(m_aff,1000,520,"food1.jpg");


tree_m_aff=lookup_widget(m_aff,"treeview1");
afficher_menu(tree_m_aff);
}


void
on_n_menu_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;


m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_m_menu();
gtk_widget_show(m_modif);
gtk_init(&argc,&argv);
chang_background(m_modif,1000,520,"food1.jpg");
}


void
on_n_com_jours_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}



//.................................................................................................................................................................





//...........................................................................................................................................................
void
on_m_miseajour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *e1_1, *e1_2, *e1_3,*e2_1, *e2_2, *e2_3 ,*e3_1, *e3_2, *e3_3, *j,*sem1,*msg_error;
int t=0;

strcpy(m.pdej,"" );
strcpy(m.pdej1,"");
strcpy(m.pdej2,"" );

strcpy(m.dej,"" );
strcpy(m.dej1 ,"" );
strcpy(m.dej2,"" );

strcpy(m.dinner,"");
strcpy(m.dinner1 , "");
strcpy(m.dinner2,"");

 sem1 = lookup_widget (button, "n_m_sem_spin");
   j = lookup_widget (button, "n_com_jours");
e1_1 = lookup_widget (button, "n_entry1_1");
e1_2 = lookup_widget (button, "n_entry1_2");
e1_3 = lookup_widget (button, "n_entry1_3");

e2_1 = lookup_widget (button, "n_entry2_1");
e2_2 = lookup_widget (button, "n_entry2_2");
e2_3 = lookup_widget (button, "n_entry2_3");

e3_1 = lookup_widget (button, "n_entry3_1");
e3_2 = lookup_widget (button, "n_entry3_2");
e3_3 = lookup_widget (button, "n_entry3_3");

msg_error= lookup_widget(button,"error_remp_menu");

m.sem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(sem1));

strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(j)));

strcpy(m.pdej, gtk_entry_get_text(GTK_ENTRY(e1_1)));
strcpy(m.pdej1, gtk_entry_get_text(GTK_ENTRY(e1_2)));
strcpy(m.pdej2, gtk_entry_get_text(GTK_ENTRY(e1_3)));

strcpy(m.dej, gtk_entry_get_text(GTK_ENTRY(e2_1)));
strcpy(m.dej1 , gtk_entry_get_text(GTK_ENTRY(e2_2)));
strcpy(m.dej2, gtk_entry_get_text(GTK_ENTRY(e2_3)));

strcpy(m.dinner, gtk_entry_get_text(GTK_ENTRY(e3_1)));
strcpy(m.dinner1 , gtk_entry_get_text(GTK_ENTRY(e3_2)));
strcpy(m.dinner2, gtk_entry_get_text(GTK_ENTRY(e3_3)));

es_pase(m.pdej);
es_pase(m.pdej1);
es_pase(m.pdej2);
es_pase(m.dej);
es_pase(m.dej1);
es_pase(m.dej2);
es_pase(m.dinner);
es_pase(m.dinner1);
es_pase(m.dinner2);


t=rechercher_menu(m);
if (t==1)
{
gtk_label_set_text(GTK_LABEL(msg_error),"cette jour deja existe !!");
}
else if(strcmp(m.jour,"")!=0 && strcmp(m.pdej,"")!=0 && strcmp(m.pdej1,"")!=0 && strcmp(m.pdej2,"")!=0 && strcmp(m.dej,"")!=0 && strcmp(m.dej1,"")!=0 && strcmp(m.dej2,"")!=0 && strcmp(m.dinner,"")!=0 && strcmp(m.dinner1,"")!=0 && strcmp(m.dinner2,"")!=0 ) 
{
gtk_label_set_text(GTK_LABEL(msg_error),"le modification a ete bien effectuer");
ajouter_menu(m);
}
else
{
gtk_label_set_text(GTK_LABEL(msg_error),"il faut remplire tout les champs svp !!");
}
}




void
on_n_m_supprimer_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n_sup_win;



n_sup_win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
n_sup_win=create_n_supprimer();
gtk_widget_show(n_sup_win);
gtk_init(&argc,&argv);
chang_background(n_sup_win,1000,520,"food1.jpg");
}






int sem1=0;
char j[20]="lundi";
int sem;


void
on_n_supp_lundi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"lundi");
}


void
on_n_supp_mardi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"mardi");
}


void
on_n_supp_mercredi_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"mercredi");
}


void
on_n_supp_jeudi_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"jeudi");
}


void
on_n_supp_vendredi_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"vendredi");
}


void
on_n_supp_samedi_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"samedi");
}


void
on_n_supp_dimanche_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(j,"dimanche");
}



void
on_n_supp_sem_changed                  (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
GtkWidget *sem;
sem=lookup_widget(combobox,"n_supp_sem");

if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(sem)))==0)
sem1=1;
else if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(sem)))==0)
sem1=2;
else if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(sem)))==0)
sem1=3;
else if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(sem)))==0)
sem1=4;
}


void
on_n_supp_valider_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
int k;
GtkWidget *jl, *jma, *jv,*js, *jme, *jd ,*jj,*sem,*msg_valid,*msg_er;


msg_er= lookup_widget(button,"n_supp_msg");


if (sem1==0)
{
gtk_label_set_text(GTK_LABEL(msg_er),"il faut choisir la semaine !!");
}

m.sem=sem1;
strcpy(m.jour,j);


k=rechercher_menu(m);
if (k==0)
{
gtk_label_set_text(GTK_LABEL(msg_er),"cette jour n'existe pas !!");
}else
{
gtk_label_set_text(GTK_LABEL(msg_er),"suppression validé ");
supprimer_menu(m.jour,m.sem);
}
}





void
on_n_menu_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n_modif_act;

n_modif_act=gtk_window_new(GTK_WINDOW_TOPLEVEL);
n_modif_act=create_n_m_menu();
gtk_widget_show(n_modif_act);
gtk_init(&argc,&argv);
chang_background(n_modif_act,1000,520,"food1.jpg");
}


void
on_n_m_ajouter_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *n_modifier_win;



n_modifier_win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
n_modifier_win=create_n_modifier_choix();
gtk_widget_show(n_modifier_win);
gtk_init(&argc,&argv);
chang_background(n_modifier_win,1000,520,"food1.jpg");

}




int mc=1;
void
on_modifier_menu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
menu n;
GtkWidget *m_e1_1, *m_e1_2, *m_e1_3,*m_e2_1, *m_e2_2, *m_e2_3 ,*m_e3_1, *m_e3_2, *m_e3_3, *j,*sem1,*msg_error;
int t=0;

strcpy(m.pdej,"");
strcpy(m.pdej1,"");
strcpy(m.pdej2,"");

strcpy(m.dej,"");
strcpy(m.dej1,"");
strcpy(m.dej2,"");

strcpy(m.dinner,"");
strcpy(m.dinner1,"");
strcpy(m.dinner2,"");


     j = lookup_widget (button, "comboboxentry_jour_modifier");
m_e1_1 = lookup_widget (button, "modif_pdej");
m_e1_2 = lookup_widget (button, "modif_pdej1");
m_e1_3 = lookup_widget (button, "modif_pdej2");

m_e2_1 = lookup_widget (button, "modif_dej");
m_e2_2 = lookup_widget (button, "modif_dej1");
m_e2_3 = lookup_widget (button, "modif_dej2");

m_e3_1 = lookup_widget (button, "modif_dinner");
m_e3_2 = lookup_widget (button, "modif_dinner1");
m_e3_3 = lookup_widget (button, "modif_dinner2");

msg_error= lookup_widget(button,"error_modifier_msg");

//gtk_entry_set_text(GTK_ENTRY(m_e1_1),"cette jour n'existe !!");

strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(j)));

strcpy(m.pdej,gtk_entry_get_text(GTK_ENTRY(m_e1_1)));
strcpy(m.pdej1,gtk_entry_get_text(GTK_ENTRY(m_e1_2)));
strcpy(m.pdej2,gtk_entry_get_text(GTK_ENTRY(m_e1_3)));

strcpy(m.dej,gtk_entry_get_text(GTK_ENTRY(m_e2_1)));
strcpy(m.dej1,gtk_entry_get_text(GTK_ENTRY(m_e2_2)));
strcpy(m.dej2,gtk_entry_get_text(GTK_ENTRY(m_e2_3)));

strcpy(m.dinner, gtk_entry_get_text(GTK_ENTRY(m_e3_1)));
strcpy(m.dinner1 , gtk_entry_get_text(GTK_ENTRY(m_e3_2)));
strcpy(m.dinner2, gtk_entry_get_text(GTK_ENTRY(m_e3_3)));

m.sem=mc;
t=rechercher_menu(m);


if(strcmp(m.jour,"")==0)
{
gtk_label_set_text(GTK_LABEL(msg_error),"choisir le jour a modifier dabord !!");
}
else if (t==0)
{
gtk_label_set_text(GTK_LABEL(msg_error),"cette jour n'existe pas !!");
}
else if(strcmp(m.pdej,"")==0 && strcmp(m.pdej1,"")==0 && strcmp(m.pdej2,"")==0 && strcmp(m.dej,"")==0 && strcmp(m.dej1,"")==0 && strcmp(m.dej2,"")==0 && strcmp(m.dinner,"")==0 && strcmp(m.dinner1,"")==0 && strcmp(m.dinner2,"")==0) 
{
gtk_label_set_text(GTK_LABEL(msg_error),"il faut remplire au minimum un champ pour le modifier !!");
}
else
{modifier_menu(m);
gtk_label_set_text(GTK_LABEL(msg_error),"le modification a ete bien effectuer");
}

}





void
on_radiobutton_sem1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{mc=1;}
}

void
on_radiobutton_sem2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{mc=2;}
}

void
on_radiobutton_sem3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{mc=3;}
}

void
on_radiobutton_sem4_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{mc=4;}
}



void
on_modif_remplire_case_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *m_e1_1, *m_e1_2, *m_e1_3,*m_e2_1, *m_e2_2, *m_e2_3 ,*m_e3_1, *m_e3_2, *m_e3_3, *j,*sem1,*msg_error;
int t=0;

strcpy(m.pdej,"");
strcpy(m.pdej1,"");
strcpy(m.pdej2,"");

strcpy(m.dej,"" );
strcpy(m.dej1 ,"" );
strcpy(m.dej2,"" );

strcpy(m.dinner,"");
strcpy(m.dinner1 , "");
strcpy(m.dinner2,"");


     j = lookup_widget (button, "comboboxentry_jour_modifier");
m_e1_1 = lookup_widget (button, "modif_pdej");
m_e1_2 = lookup_widget (button, "modif_pdej1");
m_e1_3 = lookup_widget (button, "modif_pdej2");

m_e2_1 = lookup_widget (button, "modif_dej");
m_e2_2 = lookup_widget (button, "modif_dej1");
m_e2_3 = lookup_widget (button, "modif_dej2");

m_e3_1 = lookup_widget (button, "modif_dinner");
m_e3_2 = lookup_widget (button, "modif_dinner1");
m_e3_3 = lookup_widget (button, "modif_dinner2");

msg_error= lookup_widget(button,"error_modifier_msg");



strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(j)));

msg_error= lookup_widget(button,"error_modifier_msg");

strcpy(m.pdej1, gtk_entry_get_text(GTK_ENTRY(m_e1_1)));
strcpy(m.pdej1, gtk_entry_get_text(GTK_ENTRY(m_e1_2)));
strcpy(m.pdej2, gtk_entry_get_text(GTK_ENTRY(m_e1_3)));

strcpy(m.dej, gtk_entry_get_text(GTK_ENTRY(m_e2_1)));
strcpy(m.dej1 , gtk_entry_get_text(GTK_ENTRY(m_e2_2)));
strcpy(m.dej2, gtk_entry_get_text(GTK_ENTRY(m_e2_3)));

strcpy(m.dinner, gtk_entry_get_text(GTK_ENTRY(m_e3_1)));
strcpy(m.dinner1 , gtk_entry_get_text(GTK_ENTRY(m_e3_2)));
strcpy(m.dinner2, gtk_entry_get_text(GTK_ENTRY(m_e3_3)));

m.sem=mc;

FILE *f;
f=fopen("n_menu.txt","a+");
menu n;
t=rechercher_menu(m);

if (t==0)
{
gtk_label_set_text(GTK_LABEL(msg_error),"cette jour n'existe pas !!");
}
else if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",n.jour,n.pdej,n.pdej1,n.pdej2,n.dej,n.dej1,n.dej2,n.dinner,n.dinner1,n.dinner2,&n.sem)!=EOF)
{
    if (strcmp(m.jour,n.jour) == 0 && (n.sem==m.sem))
   {
        gtk_entry_set_text(m_e1_1,n.pdej);
	gtk_entry_set_text(m_e1_2,n.pdej1);
	gtk_entry_set_text(m_e1_3,n.pdej2);
   
	gtk_entry_set_text(m_e2_1,n.dej);
	gtk_entry_set_text(m_e2_2,n.dej1);
	gtk_entry_set_text(m_e2_3,n.dej2);
	
	gtk_entry_set_text(m_e3_1,n.dinner);
	gtk_entry_set_text(m_e3_2,n.dinner1);
	gtk_entry_set_text(m_e3_3,n.dinner2);
   }
}
gtk_label_set_text(GTK_LABEL(msg_error)," ");
}
fclose(f);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar a1_jour[20];
gchar a1_pdej[30];
gchar a1_pdej1[30];
gchar a1_pdej2[30];
gchar a1_dej[30];
gchar a1_dej1[30];
gchar a1_dej2[30];
gchar a1_dinner[30];
gchar a1_dinner1[30];
gchar a1_dinner2[30]; 
gint  a1_semaine;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&a1_jour,1,&a1_pdej,2,&a1_pdej1,3,&a1_pdej2,4,&a1_dej,5,&a1_dej1,6,&a1_dej2,7,&a1_dinner,8,&a1_dinner1,9,&a1_dinner2,10,&a1_semaine, -1);

strcpy(m.jour ,a1_jour);
strcpy(m.pdej,a1_pdej);
strcpy(m.pdej1,a1_pdej1);
strcpy(m.pdej2,a1_pdej2);
strcpy(m.dej,a1_dej2);
strcpy(m.dej1,a1_dej1);
strcpy(m.dej2,a1_dej2);
strcpy(m.dinner,a1_dinner);
strcpy(m.dinner1,a1_dinner1);
strcpy(m.dinner2,a1_dinner2);
a1_semaine=m.sem;
supprimer_menu(m.jour,m.sem);

}
}





void
on_return_sup_menu_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}

//...............................................................................................................................


//...............................................................................................................................
void
on_return_menu_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}

//...............................................................................................................................
void
on_return_modifier_choix_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}

//...............................................................................................................................

//..................................................................................................................................


void
on_meilleur_m_menu_clicked         (GtkButton       *button,
                                    gpointer         user_data)
{
GtkWidget *msg_error;
char *ch[30];
msg_error= lookup_widget(button,"n_m_meilleur");
meilleur_menu();
sprintf(ch,"le meilleur menu est de %s de la semaine %d",k.jour,k.sem);
gtk_label_set_text(GTK_LABEL(msg_error),ch);

}

//...............................................................................................................................
void
on_actualiser_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_modifier_choix();
gtk_widget_show(m_modif);
gtk_init(&argc,&argv);
chang_background(m_modif,1000,520,"food1.jpg");
}


//...............................................................................................................................
void
on_return_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
   
}




//.......................................................................................................


//...............................................................................................................................
void
on_afficher_tout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
on_n_menu_afficher_clicked             (button,user_data);
}


void
on_return_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_modif,*msg_error;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}




void
on_rechercher_menu_button_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *j,*sem,*m_aff ,*tree_m_aff;


j = lookup_widget (button, "j_r");
strcpy(m.jour, gtk_combo_box_get_active_text(GTK_COMBO_BOX(j)));

sem =lookup_widget (button, "s_r");
m.sem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(sem));





if(rechercher_menu(m))
{
rechercher_aff_menu(m);


m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_aff=create_n_afficher_menu();
gtk_widget_show(m_aff);
gtk_init(&argc,&argv);
chang_background(m_aff,1000,520,"food1.jpg");


tree_m_aff=lookup_widget(m_aff,"treeview1");
afficher_menu1(tree_m_aff);
}
else
{
m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_aff=create_n_afficher_menu();
gtk_widget_show(m_aff);
gtk_init(&argc,&argv);

chang_background(m_aff,1000,520,"food1.jpg");
tree_m_aff=lookup_widget(m_aff,"treeview1");
afficher_menu2(tree_m_aff);
}

}



void
on_n_aff_clear_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_aff ,*tree_m_aff;

FILE *f;
f=fopen("n_menu.txt","a+");
fclose(f);
remove("n_menu.txt");
f=fopen("n_menu.txt","a+");

m_aff=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_aff=create_n_afficher_menu();
gtk_widget_show(m_aff);
gtk_init(&argc,&argv);

chang_background(m_aff,1000,520,"food1.jpg");
tree_m_aff=lookup_widget(m_aff,"treeview1");
afficher_menu(tree_m_aff);
}





void
on_n_theme_1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"B.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}


void
on_n_theme_2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"A.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}


void
on_n_theme_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_n_theme_4_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"D.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}


void
on_n_theme_3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(img1,"C.jpg");
GtkWidget *m_modif;
m_modif=gtk_window_new(GTK_WINDOW_TOPLEVEL);
m_modif=create_n_admin();
gtk_widget_show(m_modif);

gtk_init(&argc,&argv);
chang_background(m_modif,750,520,img1);
}

