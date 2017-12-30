#ifndef ETUDIANTCYCLE1_HPP
#define ETUDIANTCYCLE1_HPP
#define ETUDIANT_CYCLE1_TYPE 1

#include "Etudiant.hpp"

class EtudiantCycle1: public Etudiant
{
	string anneeBac;
	string lieuBac;
	string serieBac;

public:
	EtudiantCycle1(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone,
			const string& anneeBac , const string& lieuBac , const string& serieBac);
	~EtudiantCycle1() { }

	int getClassType() { return ETUDIANT_CYCLE1_TYPE; }

	// Getters and Setters
	const string& getAnneeBac() const { return anneeBac; }
	const string& getLieuBac() const { return lieuBac; }
	const string& getSerieBac() const { return serieBac; }
};

#endif
