#include "Etudiant.hpp"
#include "Inscription.hpp"
#include "Diplome.hpp"
#include "Experience.hpp"
#include "RDV.hpp"

// Initialize static variable
list<Etudiant*> Etudiant::liste_etudiants;

Etudiant::Etudiant(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone)
{
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

void Etudiant::afficherRDV()
{
	for (RDV *rdv : liste_rdv)
	{
		rdv->afficher();
	}
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

