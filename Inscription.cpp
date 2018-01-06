#include "Inscription.hpp"
#include "Etudiant.hpp"
#include "Diplome.hpp"

Inscription::Inscription(const string& premiere_inscription, int numeroAnnee, Diplome *diplome)
{
	this->premiere_inscription = premiere_inscription;
	this->numeroAnnee = numeroAnnee;
	this->diplome = diplome;
}
