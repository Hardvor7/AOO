#include "Experience.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"

list<Experience*> Experience::liste_experiences;

Experience::Experience(const string& date_debut , const string& date_fin , const string& fonction_occupe, Entreprise *entreprise, Etudiant *etudiant)
{
	this->date_debut = date_debut;
	this->date_fin = date_fin;
	this->fonction_occupe = fonction_occupe;
	this->entreprise = entreprise;
	this->etudiant = etudiant;

	liste_experiences.push_back(this);
};
