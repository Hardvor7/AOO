#ifndef EXPERIENCE_HPP
#define EXPERIENCE_HPP

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

class Entreprise;
class Etudiant;
class Date;

class Experience
{
	static list<Experience*> liste_experiences;

	Date *dateDebut;
	Date *dateFin;
	string fonctionOccupe;
	Etudiant *etudiant;
	Entreprise *entreprise;

public:
	Experience(Date *dateDebut, Date *dateFin , const string& fonctionOccupe, Entreprise *entreprise, Etudiant *etudiant);

	// Getters and Setters
	static list<Experience*>& getEtudiants() { return liste_experiences; }

	Date* getDateDebut() const { return dateDebut; }
	Date* getDateFin() const { return dateFin; }
	const string& getFonctionOccupe() const { return fonctionOccupe; }
	Etudiant* getEtudiant() const { return etudiant; }
	Entreprise* getEntreprise() const { return entreprise; }
};

#endif
