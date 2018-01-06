#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
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

void AjoutRDV(bool deplacement = false, Etudiant *etudiant = nullptr, Entreprise *entreprise = nullptr)
{
	string userInput;
	Date *date;
	Heure *heureDebut;
	Heure *heureFin;

	if (!deplacement)
	{
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
	}

	cout << "Date du rendez-vous (JJ/MM/AAAA): " << endl;
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
		cout << "SUCCES: Rendez-vous " << (deplacement ? "déplacé" : "ajouté" ) << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible " << (deplacement ? "de déplacer" : "d'ajouter" ) <<" le rendez-vous: " << e.what() << endl;
	}
}

void deplacerRDV(RDV *rdv)
{
	Etudiant *etudiant = rdv->getEtudiant();
	Entreprise *entreprise = rdv->getEntreprise();
	rdv->supprimerRdv();


	cout << endl << "Menu principale > Gerer rendez-vous > Modifier rendez-vous > Deplacer rendez-vous" << endl;
	cout << "----------------" << endl;
	AjoutRDV(true, etudiant, entreprise);

}

void ModifierRDV()
{
	string userInput;
	Etudiant *etudiant;
	RDV *rdv;

	cout << "Saisir le numero de l'étudiant" << endl;

	while (true)
	{
		cin >> userInput;
		etudiant = Etudiant::searchByNum(atoi(userInput.c_str()));
		if (etudiant != nullptr)
				break;
		cout << "ERREUR: Etudiant introuvable" << endl;
	}

	etudiant->afficherRdv();
	cout << endl << "Choisir le numero correspondant au rendez-vous à modifier:" << endl;

	int numero;
	while (true)
	{
		cin >> numero;
		if (numero > 0 && numero <= (int)etudiant->getListeRdvs().size())
			break;
		cout << "ERREUR: Numero invalide" << endl;
	}

	int n = 1;
	for(RDV *r : etudiant->getListeRdvs())
	{
		if (n == numero)
		{
			rdv = r;
			break;
		}
		n++;
	}

	int reponse = 0;
	while (true)
	{

		cout << endl << "Menu principale > Gerer rendez-vous > Modifier rendez-vous" << endl;
		cout << "----------------" << endl;
		cout << "1. Deplacer" << endl;
		cout << "2. Supprimer" << endl;
		cout << "3. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 3);
		switch (reponse)
		{
			case 1:
				deplacerRDV(rdv);
				return;

			case 2:
				rdv->supprimerRdv();
				cout << endl << "SUCCES: le rendez-vous a bien été supprimé" << endl;
				return;

			default:
				cout << endl;
				return;
		}
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
		cout << ( i == 0 ? "Date de début" : "Date de fin") << " (JJ/MM/AAAA): " << endl;
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
	Date *dateObtention;

	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Ajout diplome" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie du diplome:" << endl;
	cout << "  Code, Nom national, Date d'obtention (JJ/MM/AAAA), Lieu d'obtention" << endl;

	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", 4, true);
			dateObtention = new Date(infos[2], 2);
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}


	try {
		new Diplome(atoi(infos[0].c_str()), infos[1], dateObtention, infos[3], etudiant);
		cout << "SUCCES: Diplome ajouté" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'jouter le diplome: " << e.what() << endl;
	}
}

void Inscrire(Etudiant *etudiant)
{
	string userInput;
	Date *datePremiereInscription;
	Diplome *diplome;
	int numeroAnnee;

	cout << endl << "Menu principale > Gérer etudiant > Modifier etudiant > Inscrire" << endl;
	cout << "----------------" << endl;
	cout << "Format de saisie de l'inscription:" << endl;
	cout << "  Date de la première inscription (JJ/MM/AAAA), Numero de l'année, Nom du diplome" << endl;

	vector<string> infos;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", 3, true);
			datePremiereInscription = new Date(infos[0], 2);
			if ((numeroAnnee = atoi(infos[1].c_str())) < 1)
			{
				cout << "ERREUR: numero d'année invalide" << endl;
				continue;
			}
			if ((diplome = Diplome::searchByNom(infos[2])) != nullptr)
				break;
			cout << "ERREUR: Diplome introuvable" << endl;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	new Inscription(datePremiereInscription, numeroAnnee, diplome, etudiant);
	cout << "SUCCES: Inscription enregistrée" << endl;
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
		cout << "3. Inscrire" << endl;
		cout << "4. Afficher rendez-vous" << endl;
		cout << "5. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 5);
		switch (reponse)
		{
			case 1:
				AjoutDiplome(etudiant);
				break;

			case 2:
				AjoutExperience(etudiant);
				break;

			case 3:
				Inscrire(etudiant);
				break;

			case 4:
				etudiant->afficherRdv();
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
	int numeroEtudiant, anneeBac;
	while (true)
	{
		try {
			cin >> userInput;
			if (userInput == EXIT_DIALOG_STRING) return;
			infos = split(userInput, ",", (cycle == 1 ? 8 : 6), true);
			numeroEtudiant = atoi(infos[0].c_str());
			anneeBac = atoi(infos[5].c_str());

			if (numeroEtudiant == 0)
				throw invalid_argument("Numero etudiant invalide");

			if (cycle == 1 && (anneeBac == 0 || anneeBac > 2017 || anneeBac < 1980))
				throw invalid_argument("Année du bac invalide");
			break;
		}
		catch (const invalid_argument& e) {
			cout << "ERREUR: " << e.what() << endl;
		}
	}

	try {
		if (cycle == 1)
			new EtudiantCycle1(numeroEtudiant, infos[1], infos[2], infos[3], infos[4], anneeBac, infos[6], infos[7]);
		else
			new EtudiantCycle2(numeroEtudiant, infos[1], infos[2], infos[3], infos[4], infos[5]);
		cout << "SUCCES: Etudiant ajouté" << endl;
	}
	catch (const invalid_argument& e) {
		cout << "ERREUR: Impossible d'ajouter l'etudiant: " << e.what() << endl;
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
	string userInput;
	while (true)
	{

		cout << endl << "Menu principale > Gerer entreprise" << endl;
		cout << "----------------" << endl;
		cout << "1. Ajouter entreprise" << endl;
		cout << "2. Afficher rendez-vous" << endl;
		cout << "3. Retour" << endl;
		cout << "Choisir une option: ";

		do {
			cin >> reponse;
		}
		while (reponse < 1 || reponse > 3);
		switch (reponse)
		{
			case 1:
				AjoutEntreprise();
				break;

			case 2:
				Entreprise *entreprise;
				cout << "Saisir le nom de l'entreprise" << endl;
				while (true)
				{
					cin >> userInput;
					if (userInput == EXIT_DIALOG_STRING) return;
					if ((entreprise = Entreprise::searchByNom(userInput)) != nullptr)
						break;
					cout << "ERREUR: Entreprise introuvable" << endl;
				}
				entreprise->afficherRdv();
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

			case 2:
				ModifierRDV();
				break;

			case 3:
				RDV::afficherRdv();
				break;

			default:
				cout << endl;
				return;
		}
	}
}


void remplirBDD()
{
	// Ajout des diplomes possibles
	new Diplome("BREVET");
	new Diplome("BAC");
	new Diplome("LICENCE");
	new Diplome("MASTER");

	// Ajout des Etudiants
		// Ajout des diplomes aux étudiants
		//  Ajout des Entreprises
		// Ajouter des rendez-vous
		// Ajout des experiences aux etudiants
		// Ajout des inscriptions

	new EtudiantCycle1(1,"Dupont","Julie","Limoges","0615489562", 2015, "Raoul Dautry", "S");
		new Diplome(1,"BAC", new Date("5/07/2015"), "Dautry", Etudiant::getEtudiants().back());
		new Entreprise("Ubisoft", "Toulouse", "Paul", "0606060606");
		new RDV(new Date(12,10,2017), new Heure(9,5), new Heure(9,20), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().front());
		new Experience(new Date(7,8,2012), new Date(7,12,2012) , "Chef de groupe", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(30,4,2012), 3, Diplome::searchByNom("BAC"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle1(2,"Dupond","Martin","Rennes","0651021484", 2015, "Limosin", "ES");
		new Diplome(2,"BREVET", new Date("12/03/2012"), "Melbourt", Etudiant::getEtudiants().back());
		new Entreprise("Samsung", "Paris", "Pierre", "0625301402");
		new RDV(new Date(2,2,2017), new Heure(15,10), new Heure(15,25), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().front());
		new Experience(new Date(4,5,2012), new Date(7,6,2013) , "Chef de projet", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(26,3,2013), 2, Diplome::searchByNom("BREVET"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle1(3,"Depardeut","Gerard","Strasbourg","0748650141", 2015, "Saint Joseph", "L");
		new Diplome(3,"LICENCE", new Date("13/10/2016"), "Juglai", Etudiant::getEtudiants().back());
		new Entreprise("Electronic Arts", "Lyon", "Jacques", "0705159564");
		new RDV(new Date(25,5,2017), new Heure(8,0), new Heure(8,15), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().front());
		new Experience(new Date(17,6,2012), new Date(17,12,2014) , "secretaire", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(3,12,2014), 1, Diplome::searchByNom("BAC"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle1(4,"Jerry","Justine","Marseille","0636051490", 2015, "Valadon", "STMG");
		new Diplome(4,"MASTER", new Date("25/08/2017"), "Naruto", Etudiant::getEtudiants().back());
		new Entreprise("Thales", "Bordeaux", "Marie", "0748956105");
		new RDV(new Date(1,3,2017), new Heure(18,0), new Heure(19,0), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().front());
		new Experience(new Date(28,11,2012), new Date(7,10,2014) , "assistant ingenieur", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(18,11,2011), 4, Diplome::searchByNom("LICENCE"), Etudiant::getEtudiants().back() )

	new EtudiantCycle2(5,"Jidor","Kylian","Lille","0615410231", "Info");
		new Diplome(3,"LICENCE", new Date("8/12/1999"), "Valencien", Etudiant::getEtudiants().back());
		new Entreprise("Dell", "Brest", "Thomas", "0102201012");
		new RDV(new Date(3,3,2016), new Heure(6,0), new Heure(6,10), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().back());
		new Experience(new Date(2,12,2010), new Date(7,7,2015) , "stagiare", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(21,12,2012), 3, Diplome::searchByNom("MASTER"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle2(6,"Mushu","Mathilde","Rouen","0748956215", "SVT");
		new Diplome(3,"LICENCE", new Date("5/10/2002"), "Grodes", Etudiant::getEtudiants().back());
		new Entreprise("Niantic", "Auxerre", "John", "0663528577");
		new RDV(new Date(10,6,2016), new Heure(13,0), new Heure(13,5), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().back());
		new Experience(new Date(3,9,2008), new Date(7,3,2011) , "alternant", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(4,1,2010), 5, Diplome::searchByNom("LICENCE"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle2(7,"Vades","Victor","Limoges","0630254777", "Mathematiques");
		new Diplome(2,"BREVET", new Date("25/07/2012"), "Ferry", Etudiant::getEtudiants().back());
		new Entreprise("Apple", "Dijon", "Manon", "0725140262");
		new RDV(new Date(11,8,2016), new Heure(16,0), new Heure(16,20), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().back());
		new Experience(new Date(16,2,2007), new Date(7,5,2015) , "egerie", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(7,10,2012), 3, Diplome::searchByNom("BREVET"), Etudiant::getEtudiants().back() )
		
	new EtudiantCycle2(8,"Pluchon","Lea","Agen","0730514895", "Petite Enfance");
		new Diplome(1,"BAC", new Date("5/07/2015"), "Jules", Etudiant::getEtudiants().back());
		new Entreprise("Nokia", "La Rochelle", "Fabien", "0744559902");
		new RDV(new Date(8,12,2016), new Heure(7,0), new Heure(7,12), Etudiant::getEtudiants().back(), Entreprise::getEntreprises().back());
		new Experience(new Date(22,3,2001), new Date(7,12,2013) , "ingenieur", Entreprise::getEntreprises().back() , Etudiant::getEtudiants().back() )
		new Inscription(new Date(10,6,2013), 2, Diplome::searchByNom("MASTER"), Etudiant::getEtudiants().back() )	
}

int main()
{
	remplirBDD();

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
