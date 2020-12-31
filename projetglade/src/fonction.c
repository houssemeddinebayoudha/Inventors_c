#include "fonction.h"

void ajouter (animal a) {
FILE* f;

f= fopen ("troupeaux.txt","a+");

if (f!=NULL){
fprintf (f," %s %s %s %d %d %d \n",a.id,a.type,a.sexe,a.date_naiss.jour,a.date_naiss.mois ,a.date_naiss.annee);
}


fclose(f);

}

void modifier (char id[10], animal a){
FILE* f;
animal a1;
f= fopen ("troupeaux.txt", "r+");
if (f!=NULL){
FILE* f2;

f2= fopen ("troupeauxtmp.txt","a");
while (fscanf(f," %s %s %s %d %d %d ", a1.id,a1.type, a1.sexe, &(a1.date_naiss.jour), &(a1.date_naiss.mois), &(a1.date_naiss.annee)) != EOF){

if (strcmp(a1.id,id)==0)
 {
 strcpy(a1.id,a.id);
 strcpy(a1.type,a.type);
 strcpy(a1.sexe,a.sexe);
 a1.date_naiss.jour=a.date_naiss.jour;
 a1.date_naiss.mois=a.date_naiss.mois;
 a1.date_naiss.annee=a.date_naiss.annee;

  }

fprintf(f2, " %s %s %s %d %d %d \n" ,a1.id,a1.type,a1.sexe, a1.date_naiss.jour, a1.date_naiss.mois, a1.date_naiss.annee);
}

fclose(f);
fclose(f2);

remove ("troupeaux.txt");
rename("troupeauxtmp.txt", "troupeaux.txt");

 }
   }


void supprimer (char id[10]) {
animal a;
FILE*f;

fopen("troupeaux.txt","r+");
if (f!=NULL){
FILE* f2;
f2= fopen ("troupeauxtmp.txt","a");

while (fscanf(f," %s %s %s %d %d %d" , a.id,a.type,a.sexe,&(a.date_naiss.jour),&(a.date_naiss.mois),&(a.date_naiss.annee))!=EOF) {

if(strcmp(a.id,id)!=0)
fprintf(f2, " %s %s %s %d %d %d \n" , a.id,a.type,a.sexe,a.date_naiss.jour,a.date_naiss.mois,a.date_naiss.annee);

}
fclose(f);
fclose(f2);
remove("troupeaux.txt");
rename("troupeauxtmp.txt","troupeaux.txt");
}
  }

 void afficher(GtkWidget *liste) {
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[10];
	char type[20];
	char sexe[20];
	char date[30];
	store=NULL;
store=gtk_tree_view_get_model(liste);
if (store==NULL){

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" type",renderer,"text",ETYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" date",renderer,"text",EDATE, NULL);

gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);



int i,n;
animal a;
FILE* f;


fopen("troupeaux.txt" ,"r+");
if (f==NULL){
	return
	}else{

while( fscanf (f,"%s %s %s %d %d %d", a.id,a.type,a.sexe,&(a.date_naiss.jour),&(a.date_naiss.mois),&(a.date_naiss.annee) !=EOF){sprintf(date,"%d / %d / %d",a.date_naiss.jour,a.date_naiss.mois,a.date_naiss.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,EID, id,ETYPE, type ,ESEXE,sexe,EDATE,date,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
} 

int nbr_de_trp_chaq_type( char type [20])
 {

FILE*f;
int i;
animal a;

fopen("troupeaux.txt","r+");
if (f!=NULL){

while (fscanf(f,"%s %s %s %d %d %d", a.id,a.type, a.sexe, &(a.date_naiss.jour), &(a.date_naiss.mois), &(a.date_naiss.annee))!=EOF){

if (strcmp(a.type,type)==0)
 {
   i++;
  }
} 
fclose(f);
return i;
 }
             }
