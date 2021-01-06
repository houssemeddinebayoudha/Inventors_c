#include "fonction.h"



void ajouter (ouvrier o)
{FILE*f;
f=fopen("ouvrier.txt","a");
if (f!=Null)
{
fprintf(f,"%d %s %s \n" ,o.id,o.login,o.cin,o.nom,o.prenom);
fclose(f)
}
}



void modifier (ouvrier o,int cin)
{
FILE *f;
FILE *f1;
ouvrier o1;

f=fopen("ouvrier.txt","w");
f1=fopen("ouvrier1.txt","a");

if(f!=null)
{
while(fscanf(f,"%d %s %s \n",&o1.cin,o1.nouvnom,o1.prenom))
if(o.cin!=o1.cin)
{
fprintf(f1,"%d %s %s",&o1.cin,o1.nouvnom,o1.prenom);
}
fclose(f);
fclose(f1);
remove("ouvrier.txt");
rename("ouvrier1.txt","ouvrier.txt");
}
}
void supprimer (ouvrier o,int cin)
{
ouvrier o1;
FILE *f;
FILE *f1;
f=fopen("ouvrier.txt","r");
f1=fopen("ouvrier1.txt","w");
while ((eof(f)!=null)&&(eof(f1)!=null))
{
fscanf(f,"%d %s %s",o.cin,o.nom,o.prenom);
}
if (o.cin=o1.cin)
{
fprintf(f1,"%d %s %s",o1.cin,o1.nom,o1.prenom);
}
fclose(f);
fclose(f1);
remove("ouvrier.txt");
rename("ouvrier1.txt","ouvrier.txt");
}
void afficher ()
{int i,n;
FILE f;
ouvrier o;
fopen(f);
for(i=1;i<n;i++)
{
printf("%s %d %d,&o.cin,o.nom,o.prenom);
}
fclose(f);
}





