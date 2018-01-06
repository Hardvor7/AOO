#include "Diplome.hpp"
#include "Etudiant.hpp"

// Initialize static variable
list<Diplome*> Diplome::liste_diplomes;

Diplome::Diplome(int code, const string& nom_national, Date *date_obtention, const string& lieu_obtention, Etudiant *etudiant)
{
	if (searchByCode(code) != nullptr)
		throw invalid_argument("Un diplome possède déjà ce code");

	this->code = code;
	this->nom_national = nom_national;
	this->date_obtention = date_obtention;
	this->lieu_obtention = lieu_obtention;
	this->etudiant = etudiant;

	liste_diplomes.push_back(this);
}

Diplome* Diplome::searchByCode(int code)
{
	for ( Diplome *diplome : liste_diplomes)
	{
		if (diplome->code == code)
			return diplome;
	}
	return nullptr;
}
