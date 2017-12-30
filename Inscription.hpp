#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <string>
#include <vector>

using namespace std;

class Diplome;
class Etudiant;

class Inscription
{
	int annee;
	string premiere_inscription;
	Diplome *diplome;
	vector<Etudiant*> etudiants;

public:
	Inscription(const string& premiere_inscription, int annee, Diplome *diplome);

	void ajouterEtudiant(Etudiant *etudiant) { etudiants.push_back(etudiant); }

	// Getters and Setters

	int getAnnee() const { return annee; }
	Diplome* getDiplome() const { return diplome; }
	const vector<Etudiant*>& getEtudiants() const { return etudiants; }
	const string& getPremiereInscription() const { return premiere_inscription; }
};

#endif
