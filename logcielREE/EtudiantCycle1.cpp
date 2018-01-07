#include "EtudiantCycle1.hpp"

EtudiantCycle1::EtudiantCycle1(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone,
		int anneeBac , const string& lieuBac , const string& serieBac)
:	Etudiant(numero, nom, prenom, adresse, telephone)
{
	this->anneeBac = anneeBac;
	this->lieuBac = lieuBac;
	this->serieBac = serieBac;
}
