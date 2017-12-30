#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "DateHeure.hpp"
#include "EtudiantCycle1.hpp"
#include "EtudiantCycle2.hpp"
#include "Diplome.hpp"
#include "Experience.hpp"
#include "Entreprise.hpp"
#include "Inscription.hpp"
#include "RDV.hpp"
#include "SavingSystem.hpp"

using namespace std;

void afficherRDV()
{
	for(RDV *rdv : RDV::getRdVs())
	{
		rdv->afficher();
		cout << endl;
	}

}


void AjoutEntreprise()
{
	cout << endl << "Menu principale > Gerer entresprise > Ajout entresprise" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie d'une entreprise:" << endl;
	cout << "   Nom, Adresse, Nom du contact, telephone du contact" << endl;


	string resultat;
	string infos[4];
	while (true)
	{
		bool validInfos = true;
		cin >> resultat;
		resultat += ",";
		for(int i = 0; i < 4; i++)
		{
			int pos = resultat.find(",");
			infos[i] = resultat.substr(0, pos);
			if (infos[i] == "")
			{
				cout << "Information " << i+1 << " manquante" << endl;
				validInfos = false;
				break;
			}
			resultat.erase(0, pos + 1);
		}

		if (validInfos)
			break;
	}

	new Entreprise(infos[0], infos[1], infos[2], infos[3]);
	cout << "Etudiant ajoute avec succes" << endl;
}


//A VOIR SI ON CHERCHE L'ENTREPRISE IL FAUT L'AJOUTER SI ELL EXISTE PAS ET ON TOMBRE DU COUP SUR "GERER ENTREPRISE"

void AjoutExperience(Etudiant *etudiant)
{
	string resultat;
	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Ajout experience" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie de l'experience:" << endl;
	cout << "  Date de debut, Date de fin, Fonction occupe, Nom de l'entreprise" << endl;
	cin>>resultat;

	resultat += ",";
	string infos[4];
	for(int i = 0; i < 4 ; i++)
	{
		int pos = resultat.find(",");
		infos[i] = resultat.substr(0, pos);
		resultat.erase(0, pos + 1);
	}

	Entreprise *entrprise = Entreprise::searchByNom(infos[3]);
	if (entrprise == nullptr)
	{
		cout << "Entreprise introuvable" << endl;
		return;
	}

	new Experience(infos[0], infos[1], infos[2], entrprise, etudiant);
	cout << "Experience ajoute avec succes" << endl;
}




void AjoutDiplome(Etudiant *etudiant)
{
	string resultat;
	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Ajout diplome" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie du diplome:" << endl;
	cout << "  Code, Nom national, Date d'obtention, Lieu d'obtention" << endl;
	cin >> resultat;

	resultat += ",";
	string infos[4];
	for(int i = 0; i < 4 ; i++)
	{
		int pos = resultat.find(",");
		infos[i] = resultat.substr(0, pos);
		resultat.erase(0, pos + 1);
	}
	int code = atoi(infos[0].c_str());
	new Diplome(code, infos[1], infos[2], infos[3], etudiant);
	cout << "Diplome ajouté avec succès" << endl;
}

void ModifierEtudiant()
{
	cout << "Saisir le numero de l'étudiant" << endl;

	int numeroEtudiant;
	cin >> numeroEtudiant;
	if (!Etudiant::existe(numeroEtudiant))
	{
		cout << "Numero etudiant invalide" << endl;
		return;
	}

	Etudiant *etudiant = Etudiant::searchByNum(numeroEtudiant);
	int reponse = 0;
	string a;
	while (true)
	{

		cout << endl << "Menu principale > Gerer etudiant > Modifier etudiant" << endl;
		cout << "----------------" << endl;
		cout << etudiant->getNom() << " " << etudiant->getPrenom() << " N°" << etudiant->getNumero() << endl;
		cout << "1. Ajouter diplome" << endl;
		cout << "2. Ajouter experience" << endl;
		cout << "3. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 3);
		switch (reponse)
		{
			case 1:
				AjoutDiplome(etudiant);
				break;

			case 2:
				AjoutExperience(etudiant);
				break;

			default:
				cout << endl;
				return;
		}

	}
}

void AjoutEtudiant()
{
	int cycle;
	cout << endl << "Menu principale > Gerer etudiant > Ajout etudiant" << endl;
	cout << "----------------" << endl;
	cout << "Cycle de l'etudiant (1 ou 2): ";
	do
	{
		cin >> cycle;
		if(cycle == 1)
		{
			cout << "Format de saisie cycle 1:" << endl;
			cout << "   Numero etudiant, Nom, Prenom, Adresse, Numero telephone, Annee BAC, lieu BAC, serie BAC" << endl;
			break;
		}
		else if (cycle == 2)
		{
			cout << "Format de saisie cycle 2:" << endl;
			cout << "   Numero etudiant, Nom, Prenom, Adresse, Numero telephone, Discipline" << endl;
			break;
		}
		else
		{
			cout << "Cycle inexistant" << endl;
		}
	}
	while (true);


	string resultat;
	// ajouter verification formatage saisie
	string infos[(cycle == 1) ? 8 : 6];
	while (true)
	{
		bool validInfos = true;
		cin >> resultat;
		resultat += ",";
		for(int i = 0; i < ((cycle == 1) ? 8 : 6); i++)
		{
			int pos = resultat.find(",");
			infos[i] = resultat.substr(0, pos);
			if (infos[i] == "")
			{
				cout << "Information " << i+1 << " manquante" << endl;
				validInfos = false;
				break;
			}
			resultat.erase(0, pos + 1);
		}

		if (validInfos)
			break;
	}

	int numE = atoi(infos[0].c_str());
	if (!Etudiant::existe(numE))
	{
		if (cycle == 1)
			new EtudiantCycle1(numE, infos[1], infos[2], infos[3], infos[4], infos[5], infos[6], infos[7]);
		else
			new EtudiantCycle2(numE, infos[1], infos[2], infos[3], infos[4], infos[5]);
		cout << "Etudiant ajoute avec succes" << endl;
		SavingSystem::saveEtudiants();
	}
	else
	{
		cout << "Numero étudiant invalide" << endl;
	}
}

void GererEtudiant()
{
	int reponse = 0;
	string a;
	while (true)
	{

		cout << endl << "Menu principale > Gerer etudiant" << endl;
		cout << "----------------" << endl;
		cout << "1. Ajouter etudiant" << endl;
		cout << "2. Modifier etudiant" << endl;
		cout << "3. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 3);
		switch (reponse)
		{
			case 1:
				AjoutEtudiant();
				break;

			case 2:
				ModifierEtudiant();
				break;

			default:
				cout << endl;
				return;
		}

	}
}

void GererEntreprise()
{
	int reponse = 0;
	string a;
	while (true)
	{

		cout << endl << "Menu principale > Gerer entreprise" << endl;
		cout << "----------------" << endl;
		cout << "1. Ajouter entreprise" << endl;
		cout << "2. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 2);
		switch (reponse)
		{
			case 1:
				AjoutEntreprise();
				break;

			default:
				cout << endl;
				return;
		}
	}
}

void GererRDV()
{

}

int main()
{
	/*
	Date *d1 = new Date(12, 12, 2012);
	Date *d2 = new Date(15, 12, 2012);

	Heure *h1 = new Heure(12,00);
	Heure *h2 = new Heure(12,15);
	Heure *h3 = new Heure(12,30);
	Heure *h4 = new Heure(12,45);
	Heure *h5 = new Heure(12,40);
	Heure *h6 = new Heure(13,00);

	Etudiant *E1 = new Etudiant(5,"Brault","Pierre-Louis","Limoges","0623654532");
	Entreprise *Et1 = new Entreprise("Ubisoft", "Toulouse", "Michel", "0606060606");

	afficherRDV();
	cout << "lol" << endl;
	RDV *rdv1 = new RDV(d1, h1, h2, E1, Et1);
	RDV *rdv2 = new RDV(d1, h3, h4, E1, Et1);
	RDV *rdv3 = new RDV(d1, h5, h6, E1, Et1);
	afficherRDV();

*/

	/*EtudiantCycle2 *e1 = new EtudiantCycle2(5,"Brault","Pierre-Louis","Limoges","0623654532", "info");
	Etudiant * test = e1;
	//EtudiantCycle2 *e = static_cast<EtudiantCycle2*>(Etudiant::getEtudiants().front());
	if(test->getClassType() == ETUDIANT_TYPE) {
		cout << "yes" << endl;
	}*/

	// TEST SAVING
//	EtudiantCycle2 *e1 = new EtudiantCycle2(5,"Brault","Pierre-Louis","Limoges","0623654532", "info");
//	EtudiantCycle1 *e2 = new EtudiantCycle1(1,"Leclair","Robin","Limoges","06236545123", "2015", "Raoul Dautry", "S");
//	SavingSystem::saveEtudiants();

	// TEST RESTORING
	SavingSystem::restoreEtudiants();


	/*cout << Etudiant::getEtudiants().size() << " etudiants chargés !" << endl;
	for (Etudiant *e : Etudiant::getEtudiants())
	{
		cout << e->getNom() << endl;
	}*/

	int reponse = 0;
	while(true)
	{
		cout << endl << "Menu principale" << endl;
		cout << "----------------" << endl;
		cout << "1. Gerer etudiant" << endl;
		cout << "2. Gerer entreprise" << endl;
		cout << "3. Gerer rendez-vous" << endl;
		cout << "4. Quitter" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 4);

		switch (reponse)
		{
			case 1:
				GererEtudiant();
				break;

			case 2:
				GererEntreprise();
				break;

			case 3:
				GererRDV();
				break;

			default:
				cout << "FIN..." << endl;
				return 0;
				break;
		}
	}
}
