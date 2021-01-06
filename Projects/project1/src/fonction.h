typedef struct {
int id 
int cin;
char nom[20];
char prenom[20];
}ouvrier;






void ajout (ouvrier);
void modif (int cin, char *nouveaunom);
void supprimer (int cin);
ouvrier chercher (int cin);
void afficher();
ouvrier meilleur_ouvrier();





