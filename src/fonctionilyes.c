#ifdef HAVE_CONFIG_H	
#include <config.h>
#endif

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fonctionilyes.h"
#include<gtk/gtk.h>
#include <stdbool.h>

enum
{
	EID,
	ENOM,
	EQTE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS
};


int verif(char log[],char Pw[],char role[])
{
int trouve =-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20]={"Agent du restaurant"};
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp(ch3,role)==0))
trouve=1;
}
fclose(f);
}
return trouve;
}
int ajouter_prduit(produit p)
{
    FILE *fp;
    int z;

    fp=fopen("produit.txt","a+");
    if(fp!=NULL)
        {
	
            fprintf(fp,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
z=1;
        }
        fclose(fp);
if(z)
return 1;
else 
return 0;



    
}
int modifier_quantitee(produit p,int id,int qte)
{
    FILE *fp=fopen("produit.txt","a+"),*f2=fopen("produit2.txt","a+");
  
    int z=0;
    if(fp!=NULL)
    {
        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
        {
            if(p.id==id)
            {
                  p.quantitee+=qte;
                z=1;
                fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
                 
               
               
            }
            if(p.id!=id)
            {
                
                fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
                
          
            }
        }

    }

    fclose(fp);

    remove("produit.txt");
    fclose(f2);

    rename("produit2.txt","produit.txt");
return z;


}
int modifier_quantitee2(produit p,int id,int qte)
{
    FILE *fp=fopen("produit.txt","a+"),*f2=fopen("produit2.txt","a+");

    int z=0;
    if(fp!=NULL)
    {
        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
        {
            if(p.id!=id)
            {
                fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
                
            }
            if(p.id==id)
            {
               
                p.quantitee-=qte;
    
                if(p.quantitee>=0)
                {
                 z=1;
                fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
            }
                else
                {
                p.quantitee+=qte;
                    fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);

                z=2;
                }
            }
        }

    }

    fclose(fp);
 fclose(f2);
    remove("produit.txt");
   
    rename("produit2.txt","produit.txt");

return z;


}
int supprimer_produit(produit p,int id)
{
    FILE *fp=fopen("produit.txt","a+"),*f2=fopen("produit2.txt","a+");
    int i=0;
    if(fp!=NULL)
    {
        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
        {
            if(p.id==id)
            i=1;
            if(p.id!=id)
            {

                fprintf(f2,"%d %s %d %d %d %d\n",p.id,p.nom,p.quantitee,p.jour,p.mois,p.annee);
            }

        }


    }
    fclose(fp);
    remove("produit.txt");
    fclose(f2);
    rename("produit2.txt","produit.txt");

return i;




}
produit chercher_produit(produit p, int id)
{ FILE *fp;
    produit pt;
    int i=0;
    fp=fopen("produit.txt","a+");
    if(fp!=NULL)
    {
        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
         {
                if(p.id==id)
		    {
            
            pt=p;
        
            }
           
            
    
 
    
}
fclose(fp);
	return pt;
}
}


void afficher_stock(GtkWidget *liste)
{ FILE *fp;
  	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;	

    int id;
    char nom[20];
    int quantitee;
    int jour;
    int mois;
    int annee;


    store=NULL;

    produit p;
 
	
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)

	{
		renderer=gtk_cell_renderer_text_new();
						column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);		

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",ENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("QTE",renderer,"text",EQTE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("MOIS",renderer,"text",EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ANNEE",renderer,"text",EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);		

fp=fopen("/home/ilyes/Bureau/first/src/produit.txt","a+");
    if(fp==NULL)
    {
return;
}
else
{ 	FILE *fp2;
        fp2=fopen("produit.txt","a+");

        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
        {
	
		    gtk_list_store_append(store,&iter);
            	gtk_list_store_set(store,&iter,EID,p.id,ENOM,p.nom,EQTE,p.quantitee,EJOUR,p.jour,EMOIS,p.mois,EANNEE,p.annee,-1);

        }
	fclose(fp);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
    	fclose(fp2);

}
}
int rupture_stock(produit *pt,int n)
{FILE *fp;
    produit p;
    int m,i=0;
    fp=fopen("produit.txt","a+");
    if(fp!=NULL)
    {
        while(fscanf(fp,"%d %s %d %d %d %d",&p.id,p.nom,&p.quantitee,&p.jour,&p.mois,&p.annee)!=EOF)
{
if(p.quantitee==0)
    {
        pt[i]=p;
        i++;
        n++;
    }

}
fclose(fp);
return n;
    }
}

void s_produit(produit p)
{
produit p2;
FILE *f,*g;

	f=fopen("produit.txt","r");
	g=fopen("produit2.txt","w");

	if (f==NULL || g==NULL)
		return;
	else
	{

fclose(f);
fclose(g);
remove("produit.txt");
rename("produit2.txt","produit.txt");
    }
}
void chang_background(GtkWidget *widget, int w, int h, const gchar *path)
  {                       
      gtk_widget_set_app_paintable(widget, TRUE);     //Allow window to be> to draw
      gtk_widget_realize(widget);
                          
      /*  When you change the background image, the image will overlap
   17 * At this time, you need to manually call the following function to make the window drawing area invalid and redraw the window
         Control events (ie expose events).
       */                 
      gtk_widget_queue_draw(widget);
                          
      GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(path, NULL);       //  Create image resource object
      //  w, h are the width and height of the specified picture
      GdkPixbuf *dst_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf, w    , h, GDK_INTERP_BILINEAR);
                          
      GdkPixmap *pixmap = NULL;
                          
      /*  Create pixmap image;  
   28 * NULL: no mask required;
   29 * 123: 0~255, transparent to opaque
 30      */                 
      gdk_pixbuf_render_pixmap_and_mask(dst_pixbuf, &pixmap, NULL,     128);
      //  Set a background image for the widget through pixmap, the last parameter must be: FASL E
      gdk_window_set_back_pixmap(widget->window, pixmap, FALSE);
                          
      //  Release resources         
      g_object_unref(src_pixbuf);
      g_object_unref(dst_pixbuf);
      g_object_unref(pixmap);
  }


