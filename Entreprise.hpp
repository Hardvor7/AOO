#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

#include <string>
#include <list>
#include <stdio.h>

using namespace std;

class RDV;

class Entreprise
{
	static list<Entreprise*> liste_entreprises;

	string nom;
	string adresse;
	string nomContact;
	string telephoneContact;
	list<RDV*> liste_rdvs;

public:
	Entreprise(const string& nom, const string& adresse, const string& nomContact, const string& telephoneContact);
	
	void ajouterRdv(RDV* rdv);
	void supprimerRdv(RDV *rdv);
	void afficherRdv();

	// Static methods
	static Entreprise* searchByNom(const string& nom);

	// Getters and Setters
	static list<Entreprise*>& getEntreprises() { return liste_entreprises; }

	const string& getNom() const { return nom; }
	const string& getAdresse() const { return adresse; }
	const string& getNomContact() const { return nomContact; }
	const string& getTelephoneContact() const { return telephoneContact; }
	const list<RDV*>& getListeRdvs() const { return liste_rdvs; }
};

#endif
