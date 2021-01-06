#include <stdio.h>
#include <stdlib.h>

#include "arrosage.c"


int main ()
{
/*
FILE *f;
f = fopen("/home/aziz/Projets/AzizTache/src/arrosage.txt","r");
Arrosage a;
char id[30];
char aa[30];
char annee[30];
char path[40];
if(f!=NULL)
{
while (fscanf(f,"%s %s \n" ,id,aa)!=EOF)
{
sprintf(path,"/home/aziz/Projets/AzizTache/src/%s.txt",aa);
//FILE *f1;
//f1=fopen(path,"w+");
printf("%s" ,path);
}
}
else
printf("erreur \n");

/*
f=fopen("/home/aziz/Projets/AzizTache/src/equipement.txt","r+");
do {

	printf("----------------------------------- \n");
	printf("-----------Acceuil----------------- \n");
	printf("(1)- Afficher les equipements \n");
	printf("(2)- Ajouter Un equipement    \n");
	printf("(3)- Supprimer un equipement  \n");
	printf("(4)- Modifier un  equipements \n");
	printf("(5)- Rechercher un equipements \n");
	printf("(0)- Terminer \n");
	printf("----------------------------------- \n");
	printf("----------------------------------- \n");

	printf("Entrer votre choix: ");
	scanf("%d", &choix);

	switch(choix) {

	case 1:

	
	
	
	if(f!=NULL)
	{
	while (fscanf(f,"%s %s %s %d %s \n " ,e.ref,e.marque,e.type,&e.Disponibilite,e.dateAchat)!=EOF)
  
	printf(" Reference :%s | Marque :%s | TypeEquipement :%s | Disponibilité :%d | DateAchat :%s |\n \n \n",e.ref,e.marque,e.type,e.Disponibilite,e.dateAchat);
	fclose(f);
	}


	else 
	{
	printf("Impossible d'ouvrir le fichier");
	}
	break;	
	case 2:

	
	printf("\n Saisie du reference d'equipement: ");
	scanf("%s",e.ref);
	printf("\n Saisie du type d'equipement: ");
	scanf("%s",e.type);
	printf("\n Saisie du marque: ");
	scanf("%s",e.marque);
	printf("\n Saisie du date d'achat: ");
	scanf("%s",e.dateAchat);
	printf("\n Saisie du disponibilite : ");
	scanf("%d",&e.Disponibilite);

	AjouterEquipement(e);
	break;
	
	case 3:
	
	printf("\n Saisie du reference d'equipementa supprimeé : ");
	scanf("%s",ref);
	
	supprimerEquipement(ref);
	break;
	case 4:

	
	

	printf("\n Saisie du reference d'equipement a modifier: ");
	scanf("%s",ref);

	printf("\n Saisie la nouvelle valeur du reference d'equipement: ");
	scanf("%s",e.ref);
	printf("\n Saisie le nouveau  type d'equipement: ");
	scanf("%s",e.type);
	printf("\n Saisie la nouvelle  marque d'equipement: ");
	scanf("%s",e.marque);

	printf("\n Saisie la nouvelle  date d'achat: ");
	scanf("%s",e.dateAchat);
	printf("\n Saisie la nouvelle  Disponobilité: ");
	scanf("%d",&e.Disponibilite);

	ModifierEquipement(e,ref);
	break;
	case 5:
	
	
	
	printf("\n Saisie du reference d'equipement a chercher: ");
	scanf("%s",ref);
	find=ChercherEquipement(ref);
	if(find==1)
	printf("Existe \n");
	else
	printf("n'existe pas \n");
	break;
	case 0:
	break;

	default:
	printf("Votre choix n'est pas valide");
}
}
while (choix<=5);
*/	

}
