#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fichier_nader.h"



void es_pase(char ch[])
{
int i=0;
for(i=0;ch[i]!='\0';i++)
 if (ch[i]==' ')
     ch[i]='_';

}


void espase(char ch[])
{
int i=0;
for(i=0;ch[i]!='\0';i++)
 if (ch[i]=='_')
     ch[i]=' ';

}


void tri_file()
{

FILE *f;
FILE *f1;
int sem;

int i;
int n;
char tab[30][30]={"lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche"};


f1=fopen("n_modif.txt","a+");
for(i=0;i<5;i++)
{
for(n=0;n<8;n++)
{  
    f=fopen("n_menu.txt","a+");

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,&m.sem)!=EOF)
{
    if (m.sem==i && strcmp(tab[n],m.jour)==0 )
   {
   fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,m.sem);
   }
}
fclose (f);
}

}

fclose(f1);
remove("n_menu.txt");
rename("n_modif.txt","n_menu.txt");
}





void ajouter_menu(menu m)
{

FILE *f;

// ouvrir le fichier :
f=fopen("n_menu.txt","a+");

if (f!=NULL)
{
// ecrire dans le ficher
fprintf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,m.sem);
fclose(f);
tri_file();
}

}






void modifier_menu(menu n)
{

FILE *f;
FILE *f1;

// ouvrir le fichier :
f1=fopen("n_modif.txt","a+");
f=fopen("n_menu.txt","a+");

espase(n.pdej);
espase(n.pdej1);
espase(n.pdej2);
espase(n.dej);
espase(n.dej1);
espase(n.dej2);
espase(n.dinner);
espase(n.dinner1);
espase(n.dinner2);


if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,&m.sem)!=EOF)
{
    if (strcmp(m.jour,n.jour) == 0)
    {
	if(strcmp(n.pdej,"")==0 )
	strcpy(n.pdej,m.pdej);

	if(strcmp(n.pdej1,"")==0 )
	strcpy(n.pdej1,m.pdej1);

	if(strcmp(n.pdej2,"")==0  )
        strcpy(n.pdej2,m.pdej2);

	if(strcmp(n.dej,"")==0 )
	strcpy(n.dej,m.dej);

	if(strcmp(n.dej1,"")==0 )
	strcpy(n.dej1,m.dej1);
 	
	if(strcmp(n.dej2,"")==0 )
	strcpy(n.dej2,m.dej2);

	if(strcmp(n.dinner,"")==0 )
	strcpy(n.dinner,m.dinner);

 	if(strcmp(n.dinner1,"")==0 )
	strcpy(n.dinner1,m.dinner1);

	if(strcmp(n.dinner2,"")==0 )
	strcpy(n.dinner2,m.dinner1);
 
        fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %d\n",n.jour,n.pdej,n.pdej1,n.pdej2,n.dej,n.dej1,n.dej2,n.dinner,n.dinner1,n.dinner2,n.sem);
}
    else
    fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,m.sem);
}

fclose(f1);
fclose(f);
remove("n_menu.txt");
rename("n_modif.txt","n_menu.txt");
}

//.............................................................................................................................................................
void supprimer_menu(char j[20],int sem)
{
FILE *f;
FILE *f1;

tri_file();

// ouvrir le fichier :
f1=fopen("n_modif.txt","a+");
f=fopen("n_menu.txt","a+");

if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,&m.sem)!=EOF)
{
    if (strcmp(m.jour,j)!= 0 || sem!=m.sem)
   {
   fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %d\n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,m.sem);

   }
}
fclose(f1);
fclose(f);
remove("n_menu.txt");
rename("n_modif.txt","n_menu.txt");
}
//.............................................................................................................................................................

enum
{
	JOUR,
	PDEJ,
	PDEJ1,
	PDEJ2,
	DEJ,
	DEJ1,
	DEJ2,
	DINNER,
	DINNER1,
	DINNER2,
	SEMAINE,
	COLUMNS,
};



void afficher_menu(GtkWidget *liste)
{
FILE *f;

f=fopen("n_menu.txt","a+");
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;


store=NULL;

store=gtk_tree_view_get_model(liste);

if (f==NULL)
return;
else
{

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (1)",renderer,"text",PDEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (2)",renderer,"text",PDEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (3)",renderer,"text",PDEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (1)",renderer,"text",DEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (2)",renderer,"text",DEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (3)",renderer,"text",DEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (1)",renderer,"text",DINNER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (2)",renderer,"text",DINNER1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (3)",renderer,"text",DINNER2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Semaine",renderer,"text",SEMAINE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d \n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,&m.sem)!=EOF)
{
espase(m.pdej);
espase(m.pdej1);
espase(m.pdej2);
espase(m.dej);
espase(m.dej1);
espase(m.dej2);
espase(m.dinner);
espase(m.dinner1);
espase(m.dinner2);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,m.jour,PDEJ,m.pdej,PDEJ1,m.pdej1,PDEJ2,m.pdej2,DEJ,m.dej,DEJ1,m.dej1,DEJ2,m.dej2,DINNER,m.dinner,DINNER1,m.dinner1,DINNER2,m.dinner2,SEMAINE,m.sem,-1);

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}






int rechercher_menu(menu n)
{
menu m1;
FILE *f;
int e;
e=0;
// ouvrir le fichier :
f=fopen("n_menu.txt","a+");
if (f!=NULL)
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d\n",m1.jour,m1.pdej,m1.pdej1,m1.pdej2,m1.dej,m1.dej1,m1.dej2,m1.dinner,m1.dinner1,m1.dinner2,&m1.sem)!=EOF)
{
    if (strcmp(m1.jour,n.jour)==0 && (n.sem==m1.sem))
   {
    e=1;
   }
}
fclose(f);
return(e);
}




void meilleur_menu()
{
FILE *f3;
FILE *f2;
int jours1;
int r1;
float d1;
float some=0;
int c=0;
int day=0;
int j_sem;
float min=2000;
int sem=0;
int c1=0;
int j=0;
int i=0;

remove("day.txt");
f3=fopen("dechets.txt","a+");
f2=fopen("day.txt","a+");

if (f3!=NULL)
for(i=0;i<87;i++)
{  
   fscanf(f3,"%d %d %f\n",&jours1,&r1,&d1);
   c++;
   some=some+d1;

	if (c==3)
	{
	day++;
	fprintf(f2,"%d %f \n",day,some);
	some=0;
	c=0;
	}

}

fclose(f3);
fclose(f2);
f2=fopen("day.txt","a+");
c=0;
sem=1;

   while(fscanf(f2,"%d %f \n",&day,&some)!=EOF)
   {
   c++;
	 
	if (c==7)
	{
	sem++;
	}

	if(some<min)
	 { min=some;
   	   j=day;
		while(j>7)
	 	{
		j=j-7;
		}
          j_sem=sem;  
         }
   }
switch (j)
{
    case 1:
    strcpy(k.jour,"lundi");
    break;
    
    case 2:
    strcpy(k.jour,"mardi");
    break;

    case 3:
    strcpy(k.jour,"mercredi");
    break;
    
    case 4:
    strcpy(k.jour,"jeudi");
    break;

    case 5:
    strcpy(k.jour,"vendredi");
    break;
    
    case 6:
    strcpy(k.jour,"samedi");
    break;

    case 7:
    strcpy(k.jour,"dimanche");
    break;
}

k.sem=j_sem;
fclose(f2);
remove("day.txt");
}



menu l;
void rechercher_aff_menu(menu n)
{
FILE *f;
FILE *r;

r=fopen("rech.txt","a+");
remove("rech.txt");

r=fopen("rech.txt","a+");

f=fopen("n_menu.txt","a+");

if (f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d \n",n.jour,n.pdej,n.pdej1,n.pdej2,n.dej,n.dej1,n.dej2,n.dinner,n.dinner1,n.dinner2,&n.sem)!=EOF)
{
if(strcmp(m.jour,n.jour)==0 && n.sem==m.sem)
{
fprintf(r,"%s %s %s %s %s %s %s %s %s %s %d \n",n.jour,n.pdej,n.pdej1,n.pdej2,n.dej,n.dej1,n.dej2,n.dinner,n.dinner1,n.dinner2,n.sem);
}
}
fclose(f);
fclose(r);


}
}

//...............................................................................................................................



void afficher_menu1(GtkWidget *liste)
{
FILE *f;

f=fopen("rech.txt","a+");
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;


store=NULL;

store=gtk_tree_view_get_model(liste);

if (f==NULL)
return;
else
{

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (1)",renderer,"text",PDEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (2)",renderer,"text",PDEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (3)",renderer,"text",PDEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (1)",renderer,"text",DEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (2)",renderer,"text",DEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (3)",renderer,"text",DEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (1)",renderer,"text",DINNER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (2)",renderer,"text",DINNER1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (3)",renderer,"text",DINNER2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Semaine",renderer,"text",SEMAINE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %d \n",m.jour,m.pdej,m.pdej1,m.pdej2,m.dej,m.dej1,m.dej2,m.dinner,m.dinner1,m.dinner2,&m.sem)!=EOF)
{
espase(m.pdej);
espase(m.pdej1);
espase(m.pdej2);
espase(m.dej);
espase(m.dej1);
espase(m.dej2);
espase(m.dinner);
espase(m.dinner1);
espase(m.dinner2);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,m.jour,PDEJ,m.pdej,PDEJ1,m.pdej1,PDEJ2,m.pdej2,DEJ,m.dej,DEJ1,m.dej1,DEJ2,m.dej2,DINNER,m.dinner,DINNER1,m.dinner1,DINNER2,m.dinner2,SEMAINE,m.sem,-1);

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}


//...............................................................................................................................



void afficher_menu2(GtkWidget *liste)
{



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;


store=NULL;

store=gtk_tree_view_get_model(liste);

{

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (1)",renderer,"text",PDEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (2)",renderer,"text",PDEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("P-dej (3)",renderer,"text",PDEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (1)",renderer,"text",DEJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (2)",renderer,"text",DEJ1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dej (3)",renderer,"text",DEJ2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (1)",renderer,"text",DINNER,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (2)",renderer,"text",DINNER1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Dinner (3)",renderer,"text",DINNER2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Semaine",renderer,"text",SEMAINE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);


strcpy(m.pdej,"-----");
strcpy(m.pdej1,"-----");
strcpy(m.pdej2,"-----");
strcpy(m.dej,"-----");
strcpy(m.dej1,"-----");
strcpy(m.dej2,"-----");
strcpy(m.dinner,"-----");
strcpy(m.dinner1,"-----");
strcpy(m.dinner2,"n'existe pas !!");

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,m.jour,PDEJ,m.pdej,PDEJ1,m.pdej1,PDEJ2,m.pdej2,DEJ,m.dej,DEJ1,m.dej1,DEJ2,m.dej2,DINNER,m.dinner,DINNER1,m.dinner1,DINNER2,m.dinner2,SEMAINE,m.sem,-1);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}



