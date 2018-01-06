#include "Etudiant.hpp"
#include "Inscription.hpp"
#include "Experience.hpp"
#include "Entreprise.hpp"
#include "DateHeure.hpp"
#include "Diplome.hpp"
#include "RDV.hpp"

// Initialize static variable
list<Etudiant*> Etudiant::liste_etudiants;

Etudiant::Etudiant(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone)
{
	if (existe(numero))
		throw invalid_argument("L'etudiant existe déjà");

	this->numero = numero;
	this->nom = nom;
	this->prenom = prenom;
	this->adresse = adresse;
	this->telephone = telephone;

	inscription = nullptr;
	liste_etudiants.push_back(this);
}

void Etudiant::inscrire(Inscription *inscription)
{
	this->inscription = inscription;
	this->inscription->ajouterEtudiant(this);
}

void Etudiant::ajouterRdv(RDV *rdv)
{
	list<RDV*>::iterator it;
	for (it = liste_rdvs.begin(); it != liste_rdvs.end(); it++)
	{
		if ((*rdv) < (**it))
		{
			liste_rdvs.insert(it, rdv);
			return;
		}
	}

	liste_rdvs.push_back(rdv);
}

void Etudiant::supprimerRdv(RDV *rdv)
{
	liste_rdvs.remove(rdv);
}

void Etudiant::afficherRdv()
{
	int n = 1;
	cout << endl << "Nombre de rendez-vous: " << liste_rdvs.size() << endl;
	cout << "_________________________________________________" << endl;
	cout << "|    |     Date     |    Heure    |  Entrepise  |" << endl;
	for(RDV *rdv : liste_rdvs)
	{
		cout << "|----+--------------+-------------+-------------|" << endl;
			printf("| %2d |  %10s  | %5s-%5s | %-12s|\n", n, rdv->getDate()->toString().c_str(), rdv->getHeureDebut()->toString().c_str(), rdv->getHeureFin()->toString().c_str(), rdv->getEntreprise()->getNom().c_str());
		n++;
	}
	cout << "|____|______________|_____________|_____________|" << endl;
}

bool Etudiant::existe(int numero)
{
	for (Etudiant *etudiant : liste_etudiants)
	{
		if (etudiant->numero == numero)
			return true;
	}
	return false;
}

Etudiant* Etudiant::searchByNum(int numE)
{
	for ( Etudiant *etudiant : liste_etudiants)
	{
		if (etudiant->numero == numE)
			return etudiant;
	}
	return nullptr;
}

