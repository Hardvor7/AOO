#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <string>
#include <vector>

using namespace std;

class Diplome;
class Etudiant;

class Inscription
{
	string premiere_inscription;
	int numeroAnnee;
	Diplome *diplome;
	vector<Etudiant*> etudiants;

public:
	Inscription(const string& premiere_inscription, int numeroAnnee, Diplome *diplome);

	void ajouterEtudiant(Etudiant *etudiant) { etudiants.push_back(etudiant); }

	// Getters and Setters

	int getNumeroAnnee() const { return numeroAnnee; }
	Diplome* getDiplome() const { return diplome; }
	const vector<Etudiant*>& getEtudiants() const { return etudiants; }
	const string& getPremiereInscription() const { return premiere_inscription; }
};

#endif
