#include "Inscription.hpp"
#include "Etudiant.hpp"
#include "Diplome.hpp"

Inscription::Inscription(const string& premiere_inscription, int annee, Diplome *diplome)
{
	this->premiere_inscription = premiere_inscription;
	this->annee = annee;
	this->diplome = diplome;
}
