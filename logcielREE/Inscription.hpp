#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <string>
#include <vector>

using namespace std;

class Diplome;
class Etudiant;
class Date;

class Inscription
{
	Date *datePemiereInscription;
	int numeroAnnee;
	Diplome *diplome;
	Etudiant* etudiant;

public:
	Inscription(Date *datePemiereInscription, int numeroAnnee, Diplome *diplome, Etudiant *etudiant);

	// Getters and Setters
	int getNumeroAnnee() const { return numeroAnnee; }
	Date* getPremiereInscription() const { return datePemiereInscription; }
	Diplome* getDiplome() const { return diplome; }
	Etudiant* getEtudiant() const { return etudiant; }
};

#endif
