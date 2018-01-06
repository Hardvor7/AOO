#include "Inscription.hpp"
#include "Etudiant.hpp"
#include "Diplome.hpp"

Inscription::Inscription(Date *datePemiereInscription, int numeroAnnee, Diplome *diplome, Etudiant *etudiant)
{
	this->datePemiereInscription = datePemiereInscription;
	this->numeroAnnee = numeroAnnee;
	this->diplome = diplome;
	this->etudiant = etudiant;

	etudiant->inscrire(this);
}
