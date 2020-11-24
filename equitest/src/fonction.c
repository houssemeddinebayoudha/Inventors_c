#include"fonction.h"

void ajouter(equi e){
FILE* f;

f=fopen("equipement.txt","a+");

if (f!=NULL){
fprintf(f,"%s %s %c %d %d %d %d\n",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);
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

}


equi chercher(char id[20]){

}

void afficher(){

}



