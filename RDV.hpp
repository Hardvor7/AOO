#ifndef RDV_HPP
#define RDV_HPP

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

using namespace std;

class Entreprise;
class Etudiant;
class Date;
class Heure;

class RDV
{
	static list<RDV*> liste_rdvs;

	Date *date;
	Heure *heureDebut;
	Heure *heureFin;
	Etudiant *etudiant;
	Entreprise *entreprise;

	void ajoutComparatifRDV();
	bool chevauche(RDV rdv);

public:
	RDV(Date *date, Heure *heureDebut, Heure *heureFin, Etudiant *etudiant, Entreprise *entreprise);

	void supprimerRdv();
	bool operator<(RDV rdv);
	bool operator==(RDV rdv);
	
	// Getters and Setters
	static list<RDV*>& getRdvs() { return liste_rdvs; }
	static void afficherRdv();

	Date* getDate() const { return date; }
	Heure* getHeureDebut() const { return heureDebut; }
	Heure* getHeureFin() const { return heureFin; }
	Etudiant* getEtudiant() const { return etudiant; }
	Entreprise* getEntreprise() const { return entreprise; }
};

#endif
