#include "arrosage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum   
{       ID,
        DATEA,
	COLUMN,
	
};


///////////////////////Séparation

int is_empty(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}
void AjouterArrosage( Arrosage e)
{

FILE *f=NULL;

f=fopen("arrosage.txt","a+");

if(f!=NULL)
{

fprintf(f,"%s %d %d %d \n",e.id_plante,e.dateArrosage.annee,e.dateArrosage.mois,e.dateArrosage.jour);
fclose(f);
}
else 
printf("Impossible d'ouvrir le fichier");

}

///////////////////////Séparation

void afficher_Arrosage(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char jour[30];
	char mois[30];
	char annee[30];
	char dateComplet[30];
	
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Id_Plante",renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATEA, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		

		
		store=gtk_list_store_new (COLUMN, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("arrosage.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("arrosage.txt","a+");
			while (fscanf(f,"%s %s %s %s  \n " ,id,annee,mois,jour)!=EOF)
			{
		

		 strcpy(dateComplet,annee);
	         strcat(dateComplet,"-");
		 strcat(dateComplet,mois);
 	 	 strcat(dateComplet,"-");
		 strcat(dateComplet,jour);

		gtk_list_store_append (store,&iter);
		
		gtk_list_store_set (store, &iter, ID,id, DATEA,dateComplet, -1 );
		
		}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref(store);

}
}
}

///////////////////////Séparation



void supprimerArrosage(char ref[30]){
FILE*f=NULL;
FILE*f1=NULL;
 Arrosage e;
f=fopen("arrosage.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %d %d %d \n " ,e.id_plante,&e.dateArrosage.annee,&e.dateArrosage.mois,&e.dateArrosage.jour)!=EOF)
{
if(strcmp(ref,e.id_plante)!=0)

fprintf(f1,"%s %d %d %d \n",e.id_plante,e.dateArrosage.annee,e.dateArrosage.mois,e.dateArrosage.jour);
}

fclose(f);
fclose(f1);
remove("arrosage.txt");
rename("ancien.txt","arrosage.txt");
}

///////////////////////Séparation

void ModifierArrosage(Arrosage c , char ref[30]) {

supprimerArrosage(ref);
AjouterArrosage(c);
}

///////////////////////Séparation


void ChercherArrosage (GtkWidget *liste, char ref[30]) {

int find=0;

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[10];
	char jour[10];
	char mois[10];
	char annee[10];
	char dateComplet[30];
	 
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Id_Plante",renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATEA, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		
		store=gtk_list_store_new (COLUMN, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("arrosage.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("arrosage.txt","a+");
			while (fscanf(f,"%s %s %s %s  \n " ,id,annee,mois,jour)!=EOF)
			{
		 if(strcmp(ref,id)==0) 
		{
		 strcpy(dateComplet,annee);
	         strcat(dateComplet,"-");
		 strcat(dateComplet,mois);
 	 	 strcat(dateComplet,"-");
		 strcat(dateComplet,jour);
		gtk_list_store_append (store,&iter);
		
		gtk_list_store_set (store, &iter, ID,id, DATEA,dateComplet, -1 );
		}}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);

}
}
//return find;
}

int is_empty1(GtkWidget *entry){
char ch[30];
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ch,"")==0)return 0;
else return 1;
}

int existe1(char ver[30]) {
FILE *f;
f = fopen("arrosage.txt","r");
int find=0;
char ref[30];
if(f!=NULL)
{
while (fscanf(f,"%s" ,ref)!=EOF)
{
if(strcmp(ver,ref)==0)
find=1;
}
}
else
printf("erreur \n");
return find;
}


int compte(FILE *fichier)
{
	int c;
	int nLignes = 0;
	
 
	while((c=getc(fichier)) != EOF)
	{
		if(c=='\n')
			nLignes++;
		
	}
	return nLignes;
}




void convertir() 
{

FILE *f;
f = fopen("arrosage.txt","r");
FILE *f1;
f1 = fopen("verifier.txt","a+");

Arrosage a;
int annee;


if(f!=NULL)
 {
while (fscanf(f,"%s %d %d %d  \n " ,a.id_plante,&a.dateArrosage.annee,&a.dateArrosage.mois,&a.dateArrosage.jour)!=EOF)
  {
if(f1!=NULL)
   {

	fprintf(f1,"%d \n",a.dateArrosage.annee);
	
   }
  }

fclose(f);
fclose(f1);

 }
else
printf("erreur \n");

}


int test(int annee1)
{

int annee;
int tmp=0;
int max=0;
int rr=0;

FILE *f1;

f1 = fopen("verifier.txt","a+");
if(f1!=NULL)
   {

	while (fscanf(f1,"%d \n " ,&annee)!=EOF)
	{
		if(annee1 == annee)
		{
			tmp++;
			if(max < tmp)
			{
			max=tmp;
			rr=annee1;
			}
		}
	}
	fclose(f1);
	
   }
return max;

}


int lastTest(){
FILE *f1;

int iter=0;
int mm=0;
int aa=0;
int re=0;
f1 = fopen("louay.txt","a+");
if(f1!=NULL)
 {	
	while (fscanf(f1,"%d %d \n " ,&iter,&aa)!=EOF)
	{
	if(iter > mm)
	{
	 mm=iter;
	 re=aa;	
	}
	}

fclose(f1);
 }
return re;

}

int anneeSeche()
{

FILE *f;
FILE *f1;

convertir();

Arrosage e;

int annee;
int tmp=0;
int max=0;
int louay=0;


f = fopen("arrosage.txt","a+");
f1 = fopen("louay.txt","a+");

if(f!=NULL)
 {
while (fscanf(f,"%s %d %d %d  \n " ,e.id_plante,&e.dateArrosage.annee,&e.dateArrosage.mois,&e.dateArrosage.jour)!=EOF)
  {
	if(f1!=NULL)
   {

	louay=test(e.dateArrosage.annee);
	
	fprintf(f1,"%d %d \n",louay,e.dateArrosage.annee);
	
   }
  }


fclose(f1);
fclose(f);
	
  }

else
printf("erreur \n");
max=lastTest();
remove("louay.txt");
remove("verifier.txt");
return max;

}




















