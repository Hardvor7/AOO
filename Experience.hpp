#ifndef EXPERIENCE_HPP
#define EXPERIENCE_HPP

#include <string>
#include <list>

using namespace std;

class Entreprise;
class Etudiant;

class Experience
{
	static list<Experience*> liste_experiences;

	string date_debut;
	string date_fin;
	string fonction_occupe;
	Etudiant *etudiant;
	Entreprise *entreprise;

public:
	Experience(const string& date_debut , const string& date_fin , const string& fonction_occupe, Entreprise *entreprise, Etudiant *etudiant);

	// Getters and Setters
	static list<Experience*>& getEtudiants() { return liste_experiences; }

	const string& getDateDebut() const { return date_debut; }
	const string& getDateFin() const { return date_fin; }
	const string& getFonctionOccupe() const { return fonction_occupe; }
	Etudiant* getEtudiant() const { return etudiant; }
	Entreprise* getEntreprise() const { return entreprise; }
};

#endif
