
#include <config.h>



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"plantation.h"
#include<gtk/gtk.h>



void ajouter_plante(plantation P)
{
FILE *f;
f=fopen("plantation.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %d \n",P.type,P.saison,P.quantite);
fclose(f);
}
}

void afficher_plante(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store; 

char type[30];
char saison[30];
int quantite;
store=NULL; 

FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes("saison",renderer,"text",ESAISON,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

renderer = gtk_cell_renderer_text_new ();
Column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);
} 
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("plantation.txt","r");
if(f!=NULL)
{
return;
}
else 
{
f=fopen("plantation.txt","a+");
while(fscanf(f,"%s %s %d \n" ,type,saison,quantite)!=EOF)
{
	gtk_list_store_append (store,&iter); 
	gtk_list_store_set (store,&iter,ETYPE,type,ESAISON,saison,EQUANTITE,quantite,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
void supprimer_plante(plantation P )
{
plantation P1 ; 
FILE *f,*f1 ;
f=fopen("plantation.txt","r");
f1=fopen("plantation1.txt","w");
if(f==NULL || f1==NULL)
{
return;
}
else 
{
while(fscanf(f,"%s %s %d \n",P1.type ,P1.saison ,P1.quantite)!=EOF)
{    
if(strcmp(P.type,P1.type)!=0||strcmp(P.saison,P1.saison)!=0||strcmp(P.quantite,P1.quantite)!=0)
fprintf(f1,"%s %s %d \n" ,P1.type,P1.saison,P1.quantite);
}
}
fclose(f);
fclose(f1);
remove("plantation.txt");
rename("plantation1.txt","plantation.txt");
}
}



