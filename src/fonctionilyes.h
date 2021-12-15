#ifndef _fonctionilyes_h
#define _fonctionilyes_h
#include<gtk/gtk.h>
#include <stdbool.h>
typedef struct
{
    int id;
    char nom[20];
    int quantitee;
    int jour;
    int mois;
    int annee;

} produit;

int modifier_quantitee2(produit p,int id,int qte);

int ajouter_prduit(produit p);
int modifier_quantitee(produit p,int id,int qte);
int supprimer_produit(produit p, int id);
produit chercher_produit(produit p, int id);
void afficher_stock(GtkWidget *liste);
int rupture_stock(produit *p,int n);
int verif(char log[],char Pw[],char role[]);
void s_produit(produit p);
void chang_background(GtkWidget *widget, int w, int h, const gchar *path);

//void operation(int op,int *ilyes);

#endif
