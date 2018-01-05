#include "Experience.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "DateHeure.hpp"

list<Experience*> Experience::liste_experiences;

Experience::Experience(Date *dateDebut, Date *dateFin , const string& fonctionOccupe, Entreprise *entreprise, Etudiant *etudiant)
{
	if (*dateFin <= *dateDebut)
		throw invalid_argument( "Une experience ne peut pas finir avant d'avoir commencée" );

	this->dateDebut = dateDebut;
	this->dateFin = dateFin;
	this->fonctionOccupe = fonctionOccupe;
	this->entreprise = entreprise;
	this->etudiant = etudiant;

	liste_experiences.push_back(this);
};
