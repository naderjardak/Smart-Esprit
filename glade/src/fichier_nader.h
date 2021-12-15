#ifndef _fichier_nader_h
#define _fichier_nader_h


typedef struct
{
    char jour[20];

    char pdej[20];
     char pdej1[20];
      char pdej2[20];

    char dej[20];
      char dej1[20];
       char dej2[20];

    char dinner[20];
      char dinner1[20];
        char dinner2[20];

     int sem;

}menu;


GtkTreeIter iter;
GtkWidget *liste;

menu k;
menu m;

int sem;
int n;

int rechercher_menu(menu n);

void tri_file();

void ajouter_menu(menu m);

void afficher_menu(GtkWidget *liste);

void afficher_menu1(GtkWidget *liste);

void afficher_menu2(GtkWidget *liste);

void supprimer_menu(char j[],int sem);

void modifier_menu(menu n);

void meilleur_menu();

void espase(char ch[]);

void es_pase(char ch[]);
#endif
