#include "Diplome.hpp"
#include "Etudiant.hpp"

// Initialize static variable
list<Diplome*> Diplome::liste_diplomes;
list<Diplome*> Diplome::liste_nom_diplomes;

Diplome::Diplome(int code, const string& nom_national, Date *date_obtention, const string& lieu_obtention, Etudiant *etudiant)
{
	if (searchByCode(code) != nullptr)
		throw invalid_argument("Un diplome possède déjà ce code");

	if (searchByNom(nom_national) == nullptr)
		throw invalid_argument("Nom de diplome introuvable");

	this->code = code;
	this->nom_national = nom_national;
	this->date_obtention = date_obtention;
	this->lieu_obtention = lieu_obtention;
	this->etudiant = etudiant;

	etudiant->ajouterDiplome(this);
	liste_diplomes.push_back(this);
}

Diplome::Diplome(const string& nom_national)
{
	this->code = -1;
	this->nom_national = nom_national;
	this->date_obtention = nullptr;
	this->lieu_obtention = "";
	this->etudiant = nullptr;

	liste_nom_diplomes.push_back(this);
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

Diplome* Diplome::searchByNom(string nom)
{
	for ( Diplome *diplome : liste_nom_diplomes)
	{
		if (diplome->nom_national == nom)
			return diplome;
	}
	return nullptr;
}
