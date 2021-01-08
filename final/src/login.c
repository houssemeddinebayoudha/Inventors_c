
#include "login.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int verif(char log[20],char Pw[20]){
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
char nom[20];
char prenom[20];
int role=2;

f=fopen("utilisateur.txt","r+");

if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d",ch1,ch2,nom,prenom,&role)!=EOF){

if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)){

return role;
}


}
fclose(f);
return trouve;

}
}
/*
void ajouter(char nom[],char prenom[],char login[],char password[],int role){
FILE *f;
f=fopen("utilisateur.txt","a+");

if(f!=NULL){
fprintf(f,"%s %s %s %s %d\n",login,password,nom,prenom,role);

fclose(f);
}else{
printf("\n Error while making the file");
}

}
*/
