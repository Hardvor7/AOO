#ifndef ETUDIANTCYCLE1_HPP
#define ETUDIANTCYCLE1_HPP

#include "Etudiant.hpp"

class EtudiantCycle1: public Etudiant
{
	int anneeBac;
	string lieuBac;
	string serieBac;

public:
	EtudiantCycle1(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone,
			int anneeBac , const string& lieuBac , const string& serieBac);

	// Getters and Setters
	int getAnneeBac() const { return anneeBac; }
	const string& getLieuBac() const { return lieuBac; }
	const string& getSerieBac() const { return serieBac; }
};

#endif
