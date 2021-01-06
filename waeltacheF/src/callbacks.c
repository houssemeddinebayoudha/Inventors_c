#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include<string.h>
#include "arrosage.c"


	GtkWidget *afficher,*treeview ,*ajouter;



void
on_button5_aff                         (GtkButton       *button,
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


	ajouter=lookup_widget(objet_graphique,"InterfaceAjout_a");
	afficher = create_InterfaceAfficher_a();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview2") ;
	afficher_Arrosage(treeview);

}
}
}


void
RedirectToArr                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	afficher=lookup_widget(objet_graphique,"InterfaceAfficher");
	ajouter = create_InterfaceAfficher_a();
	gtk_widget_show (ajouter);
	gtk_widget_hide (afficher);
	treeview = lookup_widget(ajouter, "treeview2") ;
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

	afficher=lookup_widget(objet_graphique,"InterfaceAfficher_a");
	ajouter = create_InterfaceAjout_a();
	gtk_widget_show (ajouter);
	gtk_widget_hide (afficher);

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


	ajouter=lookup_widget(objet_graphique,"InterfaceAjout_a");
	afficher = create_InterfaceAfficher_a();
	gtk_widget_show (afficher);
	gtk_widget_hide (ajouter);
	
	treeview = lookup_widget(afficher, "treeview2") ;
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

	treeview = lookup_widget(afficher, "treeview2") ;
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
		
pInfo = gtk_message_dialog_new(GTK_WINDOW(ajouter),
GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO,
GTK_BUTTONS_OK,
"L'année le plus sèche est : %s",tt);
gtk_dialog_run(GTK_DIALOG(pInfo));
gtk_widget_destroy(pInfo);
}

