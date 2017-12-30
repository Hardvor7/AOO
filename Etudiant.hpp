#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP
#define ETUDIANT_TYPE 0

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Inscription;
class Diplome;
class RDV;
class Experience;

class Etudiant
{
	static list<Etudiant*> liste_etudiants;

	int numero;
	string nom;
	string prenom;
	string adresse;
	string telephone;
	Inscription *inscription;
	vector<Diplome*> diplomes;
	vector<Experience*> experiences;
	list<RDV*> liste_rdv;


public:
	Etudiant(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone);
	virtual ~Etudiant() { }

	void inscrire(Inscription *_inscription);
	void afficherRDV();

	void ajouterRdv(RDV *rdv) { liste_rdv.push_back(rdv); }

	virtual int getClassType() { return ETUDIANT_TYPE; }

	// Static methods
	static bool existe(int numero);
	static Etudiant* searchByNum(int numE);

	// Getters and Setters
	static list<Etudiant*>& getEtudiants() { return liste_etudiants; }

	int getNumero() const { return numero; }
	const string& getNom() const { return nom; }
	const string& getPrenom() const { return prenom; }
	const string& getAdresse() const { return adresse; }
	const string& getTelephone() const { return telephone; }
	Inscription* getInscription() const { return inscription; }
	const vector<Diplome*>& getDiplomes() const { return diplomes; }
	const vector<Experience*>& getExperiences() const { return experiences; }
	const list<RDV*>& getListeRdv() const { return liste_rdv; }
};

#endif
