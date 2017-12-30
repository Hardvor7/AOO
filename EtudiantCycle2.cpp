#include "EtudiantCycle2.hpp"

EtudiantCycle2::EtudiantCycle2(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone,
		const string& discipline)
:	Etudiant(numero, nom, prenom, adresse, telephone)
{
	this->discipline = discipline;
}

