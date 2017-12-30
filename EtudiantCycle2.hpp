#ifndef ETUDIANTCYCLE2_HPP
#define ETUDIANTCYCLE2_HPP
#define ETUDIANT_CYCLE2_TYPE 2

#include "Etudiant.hpp"

class EtudiantCycle2: public Etudiant
{
	string discipline;

public:
	EtudiantCycle2(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone,
			const string& discipline);
	~EtudiantCycle2() { }

	int getClassType() { return ETUDIANT_CYCLE2_TYPE; }

	// Getters and Setters
	const string& getDiscipline() const { return discipline; }
};

#endif
