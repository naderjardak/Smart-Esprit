#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionilyes.h"
#include <stdbool.h>
 int op=0;
 int date3=0;
 int qte3=0;
 	 

void
on_button7_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

FILE *f=NULL;  
GtkWidget *login, *pw, *nom, *windowAuth,*lol,*image;
char login1[20];
char passw[20];
char nom1[20];



login = lookup_widget(button,"entry2_user");
pw = lookup_widget (button,"entry3_mot");




strcpy(login1, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw, gtk_entry_get_text(GTK_ENTRY(pw)));




//ouvrir le fichier
f=fopen("utilisateur.txt","a+");
if(f!=NULL)  
{
//ecrire dans le fihchier
fprintf(f," %s  %s  \n",login1,passw);
fclose(f);
}
else
printf("\n NOT FOUND");

windowAuth=create_authen();
chang_background(windowAuth, 450, 500, "auth.jpeg");
 gtk_window_set_position(GTK_WINDOW(windowAuth), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowAuth);
lol=lookup_widget(button,"inscription");
gtk_widget_destroy(lol);

}




void
on_button5_ok_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *windowEspaceAdmin,*lol,*role1,*combo;
char user[20];
char pasw[20];
char role[20];
int trouve;

username=lookup_widget(button,"entry5_login");
password=lookup_widget(button,"entry6_pw");
role1=lookup_widget(button,"label14");
combo=lookup_widget(button,"combobox2");


strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));

strcpy(role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));

trouve=verif(user,pasw,role);
 
  if(trouve==1)  
    {
    windowEspaceAdmin=create_Admin();
    chang_background(windowEspaceAdmin, 450, 450, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

    gtk_widget_show(windowEspaceAdmin);
    lol=lookup_widget(button,"authen");
    gtk_widget_destroy(lol);
    }
    else
        gtk_label_set_text(role1,"Erreur");




}


void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
 
GtkWidget  *windowEspaceAdmin,*lol;
windowEspaceAdmin=create_fenetre_supprimer();
    chang_background(windowEspaceAdmin, 300, 300, "login.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);


gtk_widget_show(windowEspaceAdmin);

lol=lookup_widget(button,"Admin");
gtk_widget_destroy(lol);
}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
 

GtkWidget  *windowEspaceAdmin,*lol;
windowEspaceAdmin=create_fenetre_ajout();
    chang_background(windowEspaceAdmin, 600, 400, "login.jpg");
    
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowEspaceAdmin);
lol=lookup_widget(button,"Admin");
gtk_widget_destroy(lol);



}

void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_admin,*fenetre_aff,*treeview1;
  

fenetre_admin=lookup_widget(button,"Admin");
gtk_widget_destroy(fenetre_admin);

fenetre_aff=create_fenetre_afficher ();
    chang_background(fenetre_aff, 600, 500, "login.jpg");
     gtk_window_set_position(GTK_WINDOW(fenetre_aff), GTK_WIN_POS_CENTER_ALWAYS);

  gtk_widget_show (fenetre_aff);


treeview1=lookup_widget(fenetre_aff,"treeview1");
afficher_stock(treeview1);


}


void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowEspaceAdmin,*fenetre_admin;
fenetre_admin=lookup_widget(button,"Admin");
gtk_widget_destroy(fenetre_admin);
windowEspaceAdmin=create_fenetre_chercher();
    chang_background(windowEspaceAdmin, 300, 300, "login.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowEspaceAdmin);

}





void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gint *id;
gchar *nom;
gint *quantitee;
gint *jour;
gint *mois;
gint *annee;
produit p;
int n;

GtkTreeModel *model=gtk_tree_view_get_model(treeview1);
if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&quantitee,3,&jour,4,&mois,5,&annee,-1);

		p.id=id;
	  strcpy(p.nom,nom);
		p.quantitee=quantitee;
		p.jour=jour;
		p.mois=mois;
		p.annee=annee;

n=supprimer_produit(p,p.id);


	
}

}


void
on_actualiser_afficher_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1,*supp;
GtkWidget *treeview1;

w1=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
    chang_background(fenetre_afficher, 600, 500, "login.jpg");
   


gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_stock(treeview1);

}


void
on_retour_afficher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowEspaceAdmin,*fenetre_admin,*supp;
fenetre_admin=lookup_widget(button,"fenetre_afficher");

gtk_widget_destroy(fenetre_admin);

windowEspaceAdmin=create_Admin();
    chang_background(windowEspaceAdmin, 450, 450, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowEspaceAdmin);
}




void
on_button2_ajout_retour_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowEspaceAdmin,*r;
windowEspaceAdmin=create_Admin();
r=lookup_widget(button,"fenetre_ajout");
    chang_background(windowEspaceAdmin, 600, 400, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowEspaceAdmin);
gtk_widget_destroy(r);
}


void
on_chercher_icone_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *gh,*case1,*case2,*case3;
int id,l;
produit pt,p;
char c1[10]="",c2[10]="",c3[10]="",c4[20]="",date[100]="",all[100]="",intr[20]="";

  gh=lookup_widget(button,"entry6_chercher_id");
case1=lookup_widget(button,"label63");
case2=lookup_widget(button,"chercher_introuvable");

id=atoi(gtk_entry_get_text(GTK_ENTRY(gh)));

pt=chercher_produit(p,id);
if(pt.id==id)
{
gtk_label_set_text(GTK_LABEL(case2),NULL);
 gtk_label_set_text(GTK_LABEL(case1),NULL);
sprintf(c1,"%d",pt.jour);
sprintf(c2,"%d",pt.mois);
sprintf(c3,"%d",pt.annee);
sprintf(c4,"%d",pt.quantitee);


strcat(date,c1);
strcat(date,"/");

strcat(date,c2);
strcat(date,"/");

strcat(date,c3);

strcat(all,c4);
strcat(all," - ");
strcat(all,date);

 if(qte3==1)
 {
   gtk_label_set_text(GTK_LABEL(case1),NULL);
  gtk_label_set_text(GTK_LABEL(case1),c4);
 }
  if(date3==1)
  { gtk_label_set_text(GTK_LABEL(case1),NULL);

    gtk_label_set_text(GTK_LABEL(case1),date);
  }
  if(date3==1 && qte3==1)
  { gtk_label_set_text(GTK_LABEL(case1),NULL);

      gtk_label_set_text(GTK_LABEL(case1),all);
   }
}
else
{
  gtk_label_set_text(GTK_LABEL(case2),NULL);
 gtk_label_set_text(GTK_LABEL(case1),NULL);
strcpy(intr,"introuvable");
gtk_label_set_text(GTK_LABEL(case2),intr);
}

}


void
on_ajout_ajouter_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;  
GtkWidget *id, *nom, *qte,*jour,*mois,*annee, *windowEspaceAdmin,*output;

int n,z=0;
produit p;
produit pt;


id=lookup_widget(button,"entry1_id");
nom=lookup_widget(button,"entry2_nom");
qte=lookup_widget(button,"entry3_qte");
jour=lookup_widget(button,"spinbutton2_jour");
mois=lookup_widget(button,"spinbutton1_mois");
annee=lookup_widget(button,"spinbutton3_mois");
output=lookup_widget(button,"label43_err");

p.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
p.quantitee=atoi(gtk_entry_get_text(GTK_ENTRY(qte)));
p.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
p.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
p.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
pt=chercher_produit(p,p.id);

if(pt.id==p.id)
gtk_label_set_text(GTK_LABEL(output),"Produit existant");
else
{
if(p.id!=NULL && p.quantitee!=NULL && p.nom!=NULL)
{

n=ajouter_prduit(p);
if (n)
gtk_label_set_text(GTK_LABEL(output),"Produit ajoutée");
else 
gtk_label_set_text(GTK_LABEL(output),"Erreur");

}

else 
gtk_label_set_text(GTK_LABEL(output),"veuillez remplir tous les champs");
}


}









void
on_button_chercher_retour_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *windowEspaceAdmin,*r;
windowEspaceAdmin=lookup_widget(button,"fenetre_chercher");
gtk_widget_destroy(windowEspaceAdmin);
r=create_Admin();
    chang_background(r, 450, 450, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(r), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(r);

}


void
on_afficher_rupture_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *rup;
  char all[200];
  char r[100];
  char l[5];
  produit p[100];
  int n,i;


rup=lookup_widget(button,"afficher_rupture_stock");
n=rupture_stock(&p,n);
sprintf(l,"%d",n);
strcpy(all,l);
strcat(all,"  produits en rupture de stock  : \n");
for(i=0;i<n;i++)
{
  if(i!=0) 
  strcat(all," - ");

  strcpy(r,p[i].nom);
  
  strcat(all,r);
  

  }
gtk_label_set_text(GTK_LABEL(rup),all);

}








void
on_supprimer_retour_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowEspaceAdmin,*lol;
windowEspaceAdmin=create_Admin();
    chang_background(windowEspaceAdmin, 450, 450, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(windowEspaceAdmin), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(windowEspaceAdmin);
lol=lookup_widget(button,"fenetre_supprimer");
gtk_widget_destroy(lol);
}


void
on_supprimer_supprimer_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *supp,*k;
int n,id;
produit p;
supp=lookup_widget(button,"entry6");
k=lookup_widget(button,"message_supprimer");
id=atoi(gtk_entry_get_text(GTK_ENTRY(supp)));
n=supprimer_produit(p,id);
if(n==1)
 gtk_label_set_text(GTK_LABEL(k),"Produit supprimé");
 else
  gtk_label_set_text(GTK_LABEL(k),"ID introuvable");

}






void
on_button1_update_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *idd,*qtee,*msg;
int id,qte,n1,n2;
 idd=lookup_widget(button,"mod_id");
qtee=lookup_widget(button,"spinbutton1");
msg=lookup_widget(button,"label67");
produit p;

id=atoi(gtk_entry_get_text(GTK_ENTRY(idd)));
qte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(qtee));

if(op==2)

{
  gtk_label_set_text(msg,"");
  n1=modifier_quantitee(p,id,qte);
if (n1==1)
gtk_label_set_text(msg,"Ajouté avec succées");
else 
gtk_label_set_text(msg,"ID introuvable");

}
else
{
  gtk_label_set_text(msg,"");
  n2=modifier_quantitee2(p,id,qte);
if (n2==1)
gtk_label_set_text(msg,"Retiré avec succées");
else if (n2==0)
gtk_label_set_text(msg,"ID introuvable");
else
gtk_label_set_text(msg,"Operation impossible :\n  Verifier le stock");
}
}





void
on_button2_ret_update_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gc,*i;
i=lookup_widget(button,"update");
gtk_widget_destroy(i);
gc=create_Admin();
    chang_background(gc, 450, 450, "menu.jpg");
     gtk_window_set_position(GTK_WINDOW(gc), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(gc);

}


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gc,*i;
i=lookup_widget(button,"Admin");
gc=create_update();
    chang_background(gc, 300, 300, "login.jpg");
     gtk_window_set_position(GTK_WINDOW(gc), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(gc);
gtk_widget_destroy(i);
}


void
on_radiobutton2_retirer_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{  if(gtk_toggle_button_get_active(togglebutton))

  op=1;
}


void
on_radiobutton1_ajouter_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton))

op=2;
}
void
on_checkbutton2_qte_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(togglebutton))
qte3=1;
else 
qte3=0;
}
void
on_checkbutton3_date_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
    if(gtk_toggle_button_get_active(togglebutton))

date3=1;
else
date3=0;
}


void
on_retour_auth_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gc,*admin;
gc=create_authen();
admin=lookup_widget(button,"Admin");
 chang_background(gc, 450, 500, "auth.jpeg");
     gtk_window_set_position(GTK_WINDOW(gc), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_show(gc);
gtk_widget_destroy(admin);
}


void
on_sinscrire_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gc,*ins;
gc=lookup_widget(button,"authen");
ins=create_inscription();
 chang_background(ins, 500, 500, "auth.jpeg");

     gtk_window_set_position(GTK_WINDOW(ins), GTK_WIN_POS_CENTER_ALWAYS);

gtk_widget_destroy(gc);
gtk_widget_show(ins);
}



void
on_supprimer_tree_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
produit p;
s_produit(p);
}

void
on_supp_affich_tree_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  produit p;
GtkWidget  *idd;
int id,n;
idd=lookup_widget(button,"id_supp_tree");
id=atoi(gtk_entry_get_text(GTK_ENTRY(idd)));
supprimer_produit( p,id);
}

