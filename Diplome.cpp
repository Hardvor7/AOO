#include "Diplome.hpp"
#include "Etudiant.hpp"

Diplome::Diplome(int code, const string& nom_national, const string& date_obtention, const string& lieu_obtention, Etudiant *etudiant)
{
	this->code = code;
	this->nom_national = nom_national;
	this->date_obtention = date_obtention;
	this->lieu_obtention = lieu_obtention;
	this->etudiant = etudiant;
}
