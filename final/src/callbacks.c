#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "troupeaux.h"
#include "arrosage.h"
#include "login.h"

GtkWidget *afficherr,*treeview ,*ajouterr;

char temp[20]="brebi";
char tempmodif[20]="brebi";
char sexemodif[20]="male";
char typpe[20]="brebi";

char x='f';
int i=1;
char x2='f';
int kd=0;
int j=1;


void
on_buttonAfficher_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
   GtkWidget *Mestroupeaux;
   GtkWidget *affiche;
   GtkWidget *treeview1;

Mestroupeaux=lookup_widget(objet, "Mestroupeaux");

gtk_widget_destroy(Mestroupeaux);

affiche=create_afficher();

gtk_widget_show(affiche);

treeview1=lookup_widget(affiche,"treeview1");
 affficher(treeview1);

}


void
on_buttonAjout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{ 
 GtkWidget *Mestroupeaux, *Ajouterunanimal;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);
Ajouterunanimal=create_Ajouterunanimal();
gtk_widget_show(Ajouterunanimal);


}


void
on_buttonModifier_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux, *modifier;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);

modifier=create_modifier();
gtk_widget_show(modifier);

}


void
on_buttontype_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux, *type;
Mestroupeaux=lookup_widget(objet, "Mestroupeaux");
gtk_widget_destroy(Mestroupeaux);

type=create_type();
gtk_widget_show(type);

}


void
on_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*Ajouterunanimal;
Ajouterunanimal=lookup_widget(objet,"Ajouterunanimal");
gtk_widget_destroy(Ajouterunanimal);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}

void
on_retouraff_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)

{ 
GtkWidget *Mestroupeaux,*afficher;
afficher=lookup_widget(objet,"afficher");
gtk_widget_destroy(afficher);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}
void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{ 	
	GtkWidget *id;
	GtkWidget *Jour;
	GtkWidget *Mois;
	GtkWidget *Annee;
	GtkWidget *Combobox1;
	GtkWidget *Ajouterunanimal;

animal a;
 Ajouterunanimal=lookup_widget(objet, "Ajouterunanimal");
 id=lookup_widget(objet, "id");
 Jour=lookup_widget(objet,"Jour");
 Mois=lookup_widget(objet,"Mois");
 Annee=lookup_widget(objet,"Annee");
 Combobox1=lookup_widget(objet,"combobox1");
 

 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id)));
 a.date_naiss.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
 a.date_naiss.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
 a.date_naiss.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
  strcpy(a.type,temp);
ajout(a);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* sexe;
gchar* date;
animal a;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&sexe,3,&date, -1);
supprimerr(id);

}
 }










void
on_retourmodif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*modifier;
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);

}


void
on_buttonmodifier_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
	GtkWidget *id;
	GtkWidget *id1;
	GtkWidget *Jour;
	GtkWidget *Mois;
	GtkWidget *Annee;
	GtkWidget *Combobox2;
	GtkWidget *modifier;
animal a;
char idd[10];
modifier =lookup_widget(objet, "modifier" );
 id=lookup_widget(objet, "id");	
 id1=lookup_widget(objet, "id1");
 Jour=lookup_widget(objet,"Jour");
 Mois=lookup_widget(objet,"Mois");
 Annee=lookup_widget(objet,"Annee");
Combobox2=lookup_widget(objet,"combobox2");
 
 

 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id1)));
 a.date_naiss.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
 a.date_naiss.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
 a.date_naiss.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));
 strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
 strcpy(a.sexe,sexemodif);

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
modifie(idd,a);
}










void
on_OK_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *OK,*l;
	
 char ch[40];
 OK =lookup_widget(objet, "OK" );
 int k=nbr_de_trp_chaq_type(typpe);
 l=lookup_widget(objet,"label26");
sprintf(ch,"Le nombre de %s est %d",typpe,k);
gtk_label_set_text(GTK_LABEL(l),ch);

}


void
on_retourtype_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Mestroupeaux,*type;
type=lookup_widget(objet,"type");
gtk_widget_destroy(type);
Mestroupeaux=create_Mestroupeaux();
gtk_widget_show(Mestroupeaux);
}

void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
windowajout=create_ajout();
gtk_widget_show(windowajout);
}


void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

}


void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *windowdelete;
windowdelete=create_delete();
gtk_widget_show(windowdelete);*/
}


void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *windowaff,*actual;
actual=lookup_widget(button,"home");
gtk_widget_destroy(actual);
GtkWidget *treeview;
windowaff=create_window1();
gtk_widget_show(windowaff);
treeview=lookup_widget(windowaff,"treeview1");
afficher(treeview);

}


void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsearch,*actual;
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
windowsearch=create_search();
gtk_widget_show(windowsearch);
}


void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*marque,*home,*actual,*jour,*mois,*annee;
char text[20];
equi e;
id=lookup_widget (button, "id");
marque=lookup_widget (button, "marque");
actual=lookup_widget (button, "ajout");
jour=lookup_widget (button, "jour");
mois=lookup_widget (button, "combobox1");
annee=lookup_widget(button, "annee");
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(marque)));

e.etat=x;
x='f';
e.dispo=i;
i=1;
e.date_daj.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
e.date_daj.mois=atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(mois)));
e.date_daj.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
equi e1=chercher(e.id);


if((e1.dispo==10)&&(strlen(e.id)>0)){
ajouter(e);
home=create_success();
gtk_widget_destroy(actual);
gtk_widget_show(home);}
else{
home=create_failed();
gtk_widget_destroy(actual);
gtk_widget_show(home);
}
}


void
on_delete_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *id;
char idd[20];
id=lookup_widget (button,"id");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
supprimer(idd);
}


void
on_trouver_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *id,*label;
char idd[20];

id=lookup_widget (objet_graphique,"id");
label=lookup_widget (objet_graphique,"label9");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));


equi e=chercher(idd);
char aff[250];
if(e.dispo==10){
sprintf(aff,"n existe pas");
}
else
sprintf(aff,"ID %s , Marque %s , etat %c , disponiblité %d en %d/%d/%d ",e.id,e.marque,e.etat,e.dispo,e.date_daj.jour,e.date_daj.mois,e.date_daj.annee);

gtk_label_set_text(GTK_LABEL(label),aff);




}


void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *id,*etat;
char idd[20],text[20],e;
id=lookup_widget (button,"id");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));

e=x2;
x2='f';
modifier(idd,e,kd);
kd=0;
}


/*void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkTreeSelection *selection;
GtkWidget p;
gchar* id;
gchar* marque;
gchar* etat;
gchar* dispo;
gchar* date;
equi e;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);

selection=gtk_tree_view_get_selection(treeview);
if (gtk_tree_model_get_iter(model, &iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&marque,2,&etat,3,&dispo,4,&date, -1);
supprimer(id);
afficher(treeview);



}
}*/








void
on_retourner_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);
}



void
on_retourajout_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"ajout");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}


void
on_retoursearch_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual,*treeview;
actual=lookup_widget(button,"search");
gtk_widget_destroy(actual);
home=create_window1();
gtk_widget_show(home);
treeview=lookup_widget(home,"treeview1");
afficher(treeview);

}


void
on_retournermodifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual,*treeview;
actual=lookup_widget(button,"modifier");
gtk_widget_destroy(actual);
home=create_window1();
gtk_widget_show(home);
treeview=lookup_widget(home,"treeview1");
afficher(treeview);

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x='f';
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x='p';
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
i=0;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
i=1;
}


void
on_retoursuccess_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"success");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}


void
on_errorredo_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"failed");
gtk_widget_destroy(actual);
home=create_ajout();
gtk_widget_show(home);

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x2='f';
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
x2='p';

}


void
on_sup_clicked                         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
	GtkWidget* t;

	gchar* id;

	t=lookup_widget(button,"treeview1");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(t));
if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
supprimer(id);
afficher(GTK_TREE_VIEW(t));

};



}


void
on_modif_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *windowmodifier,*actual,*idd;


GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
	GtkWidget* t;

	gchar* id;

	t=lookup_widget(button,"treeview1");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(t));
if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);


};
actual=lookup_widget(button,"window1");
gtk_widget_destroy(actual);
windowmodifier=create_modifier();
gtk_widget_show(windowmodifier);

idd=lookup_widget(windowmodifier,"id");


gtk_entry_set_text(idd,id);

}




void
on_abse_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *actual,*next;
actual=lookup_widget(button,"Absence");
next=create_MrqAbs();
gtk_widget_destroy(actual);
gtk_widget_show(next);
}


void
on_taux_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *actual,*next;

actual=lookup_widget(button,"Absence");
next=create_txs();
gtk_widget_destroy(actual);
gtk_widget_show(next);



}


void
on_button12_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *actual,*next,*jour,*mois,*annee,*id;
int Jour,Mois,Annee;
char idd[20];
actual=lookup_widget(button,"MrqAbs");
jour=lookup_widget (button, "jour");
mois=lookup_widget (button, "mois");
annee=lookup_widget (button, "annee");
id=lookup_widget (button, "id");
Jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
Mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
Annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(id)));
marquer_abse(atoi(idd),Jour,Mois,Annee,j);
next=create_Absence();
gtk_widget_destroy(actual);
gtk_widget_show(next);


}


void
on_abes_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *actual,*next;
actual=lookup_widget(button,"home");
next=create_Absence();
gtk_widget_destroy(actual);
gtk_widget_show(next);

}


void
on_backv1_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"Absence");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}


void
on_gobackv2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"MrqAbs");
gtk_widget_destroy(actual);
home=create_Absence();
gtk_widget_show(home);

}


void
on_go_back_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *home,*actual;
actual=lookup_widget(button,"tauxdab");
gtk_widget_destroy(actual);
home=create_Absence();
gtk_widget_show(home);

}


void
on_tx_clicked                          (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *treeview,*entry;
GtkWidget *home,*actual;
actual=lookup_widget(button,"txs");
entry=lookup_widget(button,"entry1");
int i=atoi(gtk_entry_get_text(GTK_ENTRY(entry)));
gtk_widget_destroy(actual);
home=create_tauxdab();

gtk_widget_show(home);


treeview=lookup_widget(home,"treeview2");


tauxdabs(i,9,treeview);

}


void
on_absss_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
j=0;


}


void
on_press_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
j=1;

}


void
on_nondispo_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
kd=0;

}


void
on_dispo_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
kd=1;

}





void
on_button5_aff                         (GtkWidget       *button,
                                        gpointer         user_data)
{


	






}











void
AddArrosage                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	Arrosage p;
	GtkWidget *id,*jour, *mois, *annee;
	char ver[30];

	id=lookup_widget(objet_graphique,"IdEntry");
	jour=lookup_widget(objet_graphique,"spinbuttonJ");
	mois=lookup_widget(objet_graphique,"spinbuttonM");
	annee=lookup_widget(objet_graphique,"spinbuttonA");
	
	

	if((is_empty1(id)==0) || (is_empty1(jour)==0) || (is_empty1(mois)==0) || (is_empty1(annee)==0) )
{
		GtkWidget *control1=lookup_widget(objet_graphique,"ControlArr");
                gtk_label_set_text(GTK_LABEL(control1),"Vous devez remplir tous les champs SVP !!");

}
else {
	


	strcpy(p.id_plante,gtk_entry_get_text(GTK_ENTRY(id)));
	p.dateArrosage.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	p.dateArrosage.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateArrosage.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if((p.dateArrosage.jour >= 32) || (p.dateArrosage.mois >= 13) ||  (p.dateArrosage.annee >= 2099))
{

		GtkWidget *controld1=lookup_widget(objet_graphique,"DateArr");
                gtk_label_set_text(GTK_LABEL(controld1),"Format date invalide!!");
}

else {
	AjouterArrosage(p);


	ajouterr=lookup_widget(objet_graphique,"InterfaceAjout_a");
	afficherr = create_InterfaceAfficher_a();
	gtk_widget_show (afficherr);
	gtk_widget_hide (ajouterr);
	
	treeview = lookup_widget(afficherr, "treeview2") ;
	afficher_Arrosage(treeview);

}
}
}


void
RedirectToArr                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	afficherr=lookup_widget(objet_graphique,"InterfaceAfficher");
	ajouterr = create_InterfaceAfficher_a();
	gtk_widget_show (ajouterr);
	gtk_widget_hide (afficherr);
	treeview = lookup_widget(ajouterr, "treeview2") ;
	afficher_Arrosage(treeview);



}


void
RemoveArr                              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p ,*afficher,*w1,*pQuestion;
        
        gchar* id;
	pQuestion = gtk_message_dialog_new(GTK_WINDOW(afficher),
	GTK_DIALOG_MODAL,
	GTK_MESSAGE_QUESTION,
	GTK_BUTTONS_YES_NO,
	"Voulez vous vraiments \n Supprimer cet équipement ?");

	switch (gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_YES:

	
        
        p=lookup_widget(objet_graphique,"treeview2");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           

           supprimerArrosage(id);
	w1=lookup_widget(objet_graphique,"InterfaceAfficher_a");
	afficher = create_InterfaceAfficher_a();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	afficher_Arrosage(treeview);
	
	}
	gtk_widget_destroy(pQuestion);
           


	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pQuestion);
	break;

	}


        

}


void
RedirectAdd                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	afficherr=lookup_widget(objet_graphique,"InterfaceAfficher_a");
	ajouterr = create_InterfaceAjout_a();
	gtk_widget_show (ajouterr);
	gtk_widget_hide (afficherr);

}


void
RedirectUpdate                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *w2,*w1;
	w1 = lookup_widget(objet_graphique, "InterfaceAfficher_a") ;
	w2 = lookup_widget(objet_graphique, "InterfaceUpdate_a") ;
	w2 = create_InterfaceUpdate_a();
	gtk_widget_show (w2);
	gtk_widget_show (w1);



}


void
RedirectAffArr                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


	ajouterr=lookup_widget(objet_graphique,"InterfaceAjout_a");
	afficherr = create_InterfaceAfficher_a();
	gtk_widget_show (afficherr);
	gtk_widget_hide (ajouterr);
	
	treeview = lookup_widget(afficherr, "treeview2") ;
	afficher_Arrosage(treeview);

}


void
ChercherArr                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1,*search;
	char ss[30];
	search = lookup_widget(objet_graphique, "SearchEntryArr") ;
	w1=lookup_widget(objet_graphique,"InterfaceAfficher_a");
	if((is_empty(search)==0)  )
	{
		GtkWidget *control=lookup_widget(objet_graphique,"SearchCnt");
                gtk_label_set_text(GTK_LABEL(control),"Champ manquant!!");

	}
	else {
	strcpy(ss,gtk_entry_get_text(GTK_ENTRY(search)));
	afficher = create_InterfaceAfficher_a();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	ChercherArrosage(treeview,ss);
}
}


void
RefreshArr                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *afficher,*w1;
	w1=lookup_widget(objet_graphique,"InterfaceAfficher_a");
	afficher = create_InterfaceAfficher_a();
	gtk_widget_show (afficher);
	gtk_widget_hide (w1);

	treeview = lookup_widget(afficher, "treeview2") ;
	afficher_Arrosage(treeview);

}


void
UpdateArrFn                            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	Arrosage p;
	GtkWidget *id,*jour, *mois, *annee,*ref,*update, *control1;
	char ver[30];

	id=lookup_widget(objet_graphique,"entry2");
	ref=lookup_widget(objet_graphique,"entry3");
	jour=lookup_widget(objet_graphique,"spinbutton2");
	mois=lookup_widget(objet_graphique,"spinbutton3");
	annee=lookup_widget(objet_graphique,"spinbutton4");

if((is_empty1(id)==0) || (is_empty1(jour)==0) || (is_empty1(mois)==0) || (is_empty1(annee)==0) )
{
		control1=lookup_widget(objet_graphique,"cntrsaisie");
                gtk_label_set_text(GTK_LABEL(control1),"Vous devez remplir tous les champs SVP !!");

}
else {
	

	gtk_label_set_text(GTK_LABEL(control1),"");
	strcpy(p.id_plante,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(ref)));
	p.dateArrosage.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	p.dateArrosage.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	p.dateArrosage.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if((p.dateArrosage.jour >= 32) || (p.dateArrosage.mois >= 13) ||  (p.dateArrosage.annee >= 2099))
{

		GtkWidget *controld1=lookup_widget(objet_graphique,"DateArr1");
                gtk_label_set_text(GTK_LABEL(controld1),"Format date invalide!!");
}

else {
	ModifierArrosage(p,ver);


	update=lookup_widget(objet_graphique,"InterfaceUpdate_a");
	
	
	gtk_widget_hide (update);

	treeview = lookup_widget(afficherr, "treeview2") ;
	afficher_Arrosage(treeview);


}
}


}




void
Test                                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



}


void
AnneeSeche                             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget  *pInfo;
int find = 0;
find=anneeSeche();
char tt[10];
sprintf(tt,"%d",find);
		
pInfo = gtk_message_dialog_new(GTK_WINDOW(ajouterr),
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"L'année le plus sèche est : %s",tt);
gtk_dialog_run(GTK_DIALOG(pInfo));
gtk_widget_destroy(pInfo);
}




void
on_troubelier_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(temp,"brebi");
}


void
on_trouveau_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(temp,"veau");

}


void
on_troumale_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(sexemodif,"male");

}


void
on_troufemelle_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(sexemodif,"femelle");
}


void
on_trouveau1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(typpe,"veau");
}


void
on_troubrebi1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 strcpy(typpe,"brebi");

}


void
on_connect_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *user,*password,*windowadmin,*actual,*controletest;
	char id[20],pw[20];
user=lookup_widget(button,"user");
password=lookup_widget(button,"password");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(password)));

int tt=verif(id,pw);
controletest=lookup_widget(button,"controletest");
char ch[20];




if(tt==-1){
gtk_label_set_text(GTK_LABEL(controletest),"n existe pas");
}else if(tt==0){ 
actual=lookup_widget(button,"connexion");
gtk_widget_destroy(actual);

windowadmin=create_menu();


gtk_widget_show(windowadmin);

}else if(tt==1){
actual=lookup_widget(button,"connexion");
gtk_widget_destroy(actual);

windowadmin=create_home();


gtk_widget_show(windowadmin);
}else if(tt==2){
actual=lookup_widget(button,"connexion");
gtk_widget_destroy(actual);

windowadmin=create_Mestroupeaux();


gtk_widget_show(windowadmin);

}
else if(tt==3){
actual=lookup_widget(button,"connexion");
gtk_widget_destroy(actual);

windowadmin=create_InterfaceAfficher_a();


gtk_widget_show(windowadmin);

}


}



void
on_gestiontrp_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"menu");
gtk_widget_destroy(actual);
home=create_Mestroupeaux();
gtk_widget_show(home);

}


void
on_gestionplant_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"menu");
gtk_widget_destroy(actual);
home=create_InterfaceAfficher_a();
gtk_widget_show(home);

}


void
on_gestionequi_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *home,*actual;
actual=lookup_widget(button,"menu");
gtk_widget_destroy(actual);
home=create_home();
gtk_widget_show(home);

}

