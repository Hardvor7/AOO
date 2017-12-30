#include "Entreprise.hpp"
#include "RDV.hpp"

list<Entreprise*> Entreprise::liste_entreprises;

Entreprise::Entreprise(const string& nom, const string& adresse, const string& nomContact, const string& telephoneContact)
{
	this->nom = nom;
	this->adresse = adresse;
	this->nomContact = nomContact;
	this->telephoneContact = telephoneContact;

	liste_entreprises.push_back(this);
}