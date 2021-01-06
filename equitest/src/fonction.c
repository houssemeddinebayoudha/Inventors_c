#include"fonction.h"

void ajouter(equi e){
FILE* f;
time_t t= time(NULL);
struct tm tm = *localtime(&t);

f=fopen("equipement.txt","a+");

if (f!=NULL){
//fprintf(f,"%s %s %c %d %d %d %d\n",e.id,e.marque,e.etat,e.dispo,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
fprintf(f,"%s %s %c %d %d %d %d\n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
}

fclose(f);
}

void modifier(char id[20],char etat,int dispo){
FILE* f;

equi e;
f=fopen("equipement.txt","r+");

if (f!=NULL){
FILE* f2;
f2=fopen("equipementtmp.txt","a");
while(fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF){
if(strcmp(e.id,id)==0){
e.etat=etat;
e.dispo=dispo;
}
fprintf(f2,"%s %s %c %d %d %d %d \n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
}
fclose(f);
fclose(f2);
remove("equipement.txt");
rename("equipementtmp.txt","equipement.txt");


}


}


void supprimer(char id[20]){
equi e;
FILE* f;

f=fopen("equipement.txt","r+");
if (f!=NULL){
FILE* f2;
f2=fopen("equipementtmp.txt","a");
while(fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF){
if(strcmp(e.id,id)!=0)
fprintf(f2,"%s %s %c %d %d %d %d \n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);


}
fclose(f);
fclose(f2);
remove("equipement.txt");
rename("equipementtmp.txt","equipement.txt");
}

}


equi chercher(char id[20]){
equi e;
FILE* f;
int trouv=0;
f=fopen("equipement.txt","r+");
if(f==NULL){
printf("Error while opening");
}else{
while((fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF)&&trouv==0){
if(strcmp(e.id,id)==0){
trouv=1;
break;
}
}
if(trouv==1){
fclose(f);
e.dispo=3;
return(e);
}
else{
fclose(f);
e.dispo=10;
return(e);
}
}

}

void afficher(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
equi e;
char dispo[20];
char etat[20];
char date[30];
store=gtk_tree_view_get_model(liste);

if(store==NULL){
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" marque",renderer,"text",EMARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",EETAT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" disponibilite",renderer,"text",EDISPO, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" date",renderer,"text",EDATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


FILE * f;
f=fopen("equipement.txt","r+");
if(f==NULL){
printf("Error while opening");
}else{

while(fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF){
sprintf(date,"%d / %d / %d",e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
if(e.etat=='p'){
sprintf(etat,"%s","en panne");
}else{
sprintf(etat,"%s","fonctionne");
}
if(e.dispo==1){
sprintf(dispo,"%s","disponible");
}else{
sprintf(dispo,"%s","non disponible");
}

gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,EID, e.id,EMARQUE, e.marque,EETAT,etat,EDISPO,dispo,EDATE,date,-1);

}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
void marquer_abse(int id,int jour,int mois,int annee,int abs){
FILE* f;
f=fopen("abs.txt","a");
if (f!=NULL){
fprintf(f,"%d %d %d %d %d\n",id,jour,mois,annee,abs);


}
fclose(f);
}

void tauxdabs(int annee,int nbr,GtkWidget *liste){


char tauxx[30];

char Mois[10];

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;

store=gtk_tree_view_get_model(liste);

if(store==NULL){
renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",EMOIS, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer= gtk_cell_renderer_text_new();
column= gtk_tree_view_column_new_with_attributes(" taux",renderer,"text",ETAUX, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}


store=gtk_list_store_new (TESTS, G_TYPE_STRING, G_TYPE_STRING);



int taux[11];
float t[11];
int id,jour,mois,nanne,val;
FILE* f;
f=fopen("abs.txt","r+");
if(f!=NULL){
for(int i=0;i<12;i++){
taux[i]=0;
}
while(fscanf(f,"%d %d %d %d %d",&id,&jour,&mois,&nanne,&val)!=EOF){
if(nanne==annee){
if(val==0){
taux[mois-1]++;
}
}
}
int j=0;
do{

t[j]=(float)(taux[j]*100/(nbr*30));
sprintf(Mois,"%d",j+1);
sprintf(tauxx,"%.2f",t[j]);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,EMOIS,Mois,ETAUX,tauxx,-1);
j++;
}
while(j<12);
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste) ,GTK_TREE_MODEL (store));
g_object_unref (store);


}


}






