#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

#include <string>
#include <list>

using namespace std;

class RDV;

class Entreprise
{
	static list<Entreprise*> liste_entreprises;

	string nom;
	string adresse;
	string nomContact;
	string telephoneContact;
	list<RDV*> liste_rdv;

public:
	Entreprise(const string& nom, const string& adresse, const string& nomContact, const string& telephoneContact);
	
	void ajouterRdv(RDV* rdv) { liste_rdv.push_back(rdv); }

	// Static methods
	static Entreprise* searchByNom(int numE);

	// Getters and Setters
	static list<Entreprise*>& getEntreprises() { return liste_entreprises; }

	const string& getNom() const { return nom; }
	const string& getAdresse() const { return adresse; }
	const string& getNomContact() const { return nomContact; }
	const string& getTelephoneContact() const { return telephoneContact; }
	const list<RDV*>& getListeRdv() const { return liste_rdv; }
};

#endif
