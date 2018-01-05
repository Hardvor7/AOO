#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>

#include "DateHeure.hpp"
#include "EtudiantCycle1.hpp"
#include "EtudiantCycle2.hpp"
#include "Diplome.hpp"
#include "Experience.hpp"
#include "Entreprise.hpp"
#include "Inscription.hpp"
#include "RDV.hpp"

using namespace std;

#define EXIT_DIALOG_STRING "STOP"

vector<string> split(string inputString, string delimiter, int splitCount, bool addDelimiter)
{
	vector<string> result;
	if (addDelimiter)
		inputString += delimiter;
	for(int i = 0; i < splitCount; i++)
	{
		int pos = inputString.find(delimiter.c_str());
		result.push_back(inputString.substr(0, pos));
		if (result[i] == "")
		{
			throw invalid_argument( "Information manquante" );
		}
		inputString.erase(0, pos + 1);
	}
	return result;
}

void afficherRDV()
{
	for(RDV *rdv : RDV::getRdVs())
	{
		rdv->afficher();
		cout << endl;
	}

}

void AjoutRDV()
{
	string userInput;
	Etudiant *etudiant;
	Entreprise *entreprise;
	Date *date;
	Heure *heureDebut;
	Heure *heureFin;

	cout << endl << "Menu principale > Gerer rendez-vous > Ajout rendez-vous" << endl;
	cout << "----------------" << endl;

	cout << "Saisir le numero de l'étudiant" << endl;
	while (true)
	{
		cin >> userInput;
		if (userInput == EXIT_DIALOG_STRING) return;
		if ((etudiant = Etudiant::searchByNum(atoi(userInput.c_str()))) != nullptr)
			break;
		cout << "ERREUR: Numero etudiant invalide" << endl;
	}

	cout << "Saisir le nom de l'entreprise" << endl;
	while (true)
	{
		cin >> userInput;
		if (userInput == EXIT_DIALOG_STRING) return;
		if ((entreprise = Entreprise::searchByNom(userInput)) != nullptr)
			break;
		cout << "ERREUR: Entreprise introuvable" << endl;
	}

	cout << "Date du rendez-vous (Jour/Mois/Année): " << endl;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			date = new Date(userInput, 1);
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		cout << ( i == 0 ? "Heure de début" : "Heure de fin") << " (heure:minute): " << endl;
		while (true)
		{
			try {
				cin >> userInput;
				if (userInput == EXIT_DIALOG_STRING) return;
				( i == 0 ? heureDebut : heureFin ) = new Heure(userInput);
				break;
			}
			catch (const invalid_argument& e) {
				cout << "ERREUR: " << e.what() << endl;
			}
		}
	}

	try {
		new RDV(date, heureDebut, heureFin, etudiant, entreprise);
		cout << "SUCCES: Rendez-vous ajouté" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'jouter le rendez-vous: " << e.what() << endl;
	}
}

void AjoutEntreprise()
{
	string userInput;

	cout << endl << "Menu principale > Gerer entreprise > Ajout entreprise" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie d'une entreprise:" << endl;
	cout << "   Nom, Adresse, Nom du contact, telephone du contact" << endl;

	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", 4, true);
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	try {
		new Entreprise(infos[0], infos[1], infos[2], infos[3]);
		cout << "SUCCES: Entreprise ajoutée" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'jouter l'entreprise: " << e.what() << endl;
	}

}

void AjoutExperience(Etudiant *etudiant)
{
	string userInput;
	Date* dateDebut;
	Date* dateFin;
	Entreprise* entreprise;

	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Ajout experience" << endl;
	cout << "----------------" << endl;
	cout << " Saisir: Nom de l'entreprise,  Fonction occupe" << endl;

	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", 2, true);

			if ((entreprise = Entreprise::searchByNom(infos[0])) != nullptr)
				break;
			cout << "ERREUR: Entreprise introuvable" << endl;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		cout << ( i == 0 ? "Date de début" : "Date de fin") << " (Jour/Mois/Année): " << endl;
		while (true)
		{
			try {
				cin >> userInput;
				if (userInput == EXIT_DIALOG_STRING) return;

				( i == 0 ? dateDebut : dateFin) = new Date(userInput, 2);
				break;
			}
			catch (const invalid_argument& e) {
				cout << "ERREUR: " << e.what() << endl;
			}
		}
	}

	try {
		new Experience(dateDebut, dateFin, infos[1], entreprise, etudiant);
		cout << "SUCCES: Experience ajoutée" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'jouter l'experience: " << e.what() << endl;
	}
}




void AjoutDiplome(Etudiant *etudiant)
{
	string userInput;

	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Ajout diplome" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie du diplome:" << endl;
	cout << "  Code, Nom national, Date d'obtention, Lieu d'obtention" << endl;

	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", 4, true);
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	new Diplome(atoi(infos[0].c_str()), infos[1], infos[2], infos[3], etudiant);
	cout << "SUCCES: Diplome ajouté" << endl;
}

void ModifierEtudiant()
{
	string userInput;
	Etudiant *etudiant;

	cout << "Saisir le numero de l'étudiant" << endl;

	while (true)
	{
		cin >> userInput;
		etudiant = Etudiant::searchByNum(atoi(userInput.c_str()));
		if (etudiant != nullptr)
				break;
		cout << "ERREUR: Etudiant introuvable" << endl;

	}

	int reponse = 0;
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
	string userInput;

	cout << endl << "Menu principale > Gerer etudiant > Ajout etudiant" << endl;
	cout << "----------------" << endl;
	cout << "Cycle de l'etudiant (1 ou 2): ";

	while (true)
	{
		cin >> cycle;
		if (cycle == 1 || cycle == 2)
			break;
		cout << "ERREUR: Cycle inexistant" << endl;
	}

	cout << "Format de saisie cycle " << cycle << ":" << endl;
	if(cycle == 1)
		cout << "   Numero etudiant, Nom, Prenom, Adresse, Numero telephone, Annee BAC, lieu BAC, serie BAC" << endl;
	else
		cout << "   Numero etudiant, Nom, Prenom, Adresse, Numero telephone, Discipline" << endl;


	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", (cycle == 1 ? 8 : 6), true);
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	try {
		if (cycle == 1)
			new EtudiantCycle1(atoi(infos[0].c_str()), infos[1], infos[2], infos[3], infos[4], infos[5], infos[6], infos[7]);
		else
			new EtudiantCycle2(atoi(infos[0].c_str()), infos[1], infos[2], infos[3], infos[4], infos[5]);
		cout << "SUCCES: Etudiant ajouté" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'ajouter l'etudiant:" << e.what() << endl;
	}
}

void GererEtudiant()
{
	int reponse = 0;
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
	int reponse = 0;
	while (true)
	{

		cout << endl << "Menu principale > Gerer rendez-vous" << endl;
		cout << "----------------" << endl;
		cout << "1. Ajouter rendez-vous" << endl;
		cout << "2. Modifier rendez-vous" << endl;
		cout << "3. Liste des rendez-vous" << endl;
		cout << "4. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 4);
		switch (reponse)
		{
			case 1:
				AjoutRDV();
				break;

			case 3:
				afficherRDV();
				break;

			default:
				cout << endl;
				return;
		}
	}
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

	new EtudiantCycle2(5,"Brault","Pierre-Louis","Limoges","0623654532", "info");
	new Entreprise("1", "somewhere", "paul", "060606060");

	new EtudiantCycle1(1,"Leclair","Robin","Limoges","06236545123", "2015", "Raoul Dautry", "S");


	new RDV(new Date(12,12,2018), new Heure(12,10), new Heure(12,20), Etudiant::getEtudiants().front(), Entreprise::getEntreprises().front());

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
