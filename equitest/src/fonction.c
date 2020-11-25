#include"fonction.h"

void ajouter(equi e){
FILE* f;
time_t t= time(NULL);
struct tm tm = *localtime(&t);

f=fopen("equipement.txt","a+");

if (f!=NULL){
fprintf(f,"%s %s %c %d %d %d %d\n",e.id,e.marque,e.etat,1,tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
}

fclose(f);
}

void modifier(char id[20],char etat){
FILE* f;
int i=-1;
int l=0;
equi e;
f=fopen("equipement.txt","r+");

if (f!=NULL){
while(fscanf(f,"%s",e.id)!=EOF&&i!=0){
l++;

i=strcmp(id,e.id);
}
if(i==0){
FILE* f2;
fseek(f,0,SEEK_SET);
for(i=0;i<l;i++){
if(fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee)))
fprintf(f2,"%s %s %c %d %d %d %d \n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
}

f=f2;
free(f2);
fclose(f);
}
}

}


void supprimer(char id[20]){
equi e;
FILE* f;
FILE* f2;
f=fopen("equipement.txt","r+");
if(f==NULL){
printf("Error while opening");
}else{
while((fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF)){
if(strcmp(e.id,id)!=0){
fprintf(f2,"%s %s %c %d %d %d %d \n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
}

}
f=f2;
fclose(f2);
fclose(f);
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
}
}
if(trouv==1){
return(e);
}
else
printf("il n'existe pas");
}
fclose(f);
}

void afficher(){
equi e;
FILE * f;
f=fopen("equipement.txt","r+");
if(f==NULL){
printf("Error while opening");
}else{
while(fscanf(f,"%s %s %c %d %d %d %d",e.id,e.marque,&e.etat,&e.dispo,&(e.date_daj.jour),&(e.date_daj.mois),&(e.date_daj.annee))!=EOF){
printf("%s %s %c %d %d %d %d \n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
}
fclose(f);
}
}
