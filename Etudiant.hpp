#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

class Inscription;
class Diplome;
class RDV;
class Experience;

class Etudiant
{
	static list<Etudiant*> liste_etudiants;

protected:
	int numero;
	string nom;
	string prenom;
	string adresse;
	string telephone;
	Inscription *inscription;
	vector<Diplome*> diplomes;
	vector<Experience*> experiences;
	list<RDV*> liste_rdvs;


public:
	Etudiant(int numero, const string& nom, const string& prenom, const string& adresse, const string& telephone);

	void inscrire(Inscription *_inscription);
	void ajouterDiplome(Diplome *diplome);
	void ajouterExperience(Experience *experience);
	void ajouterRdv(RDV *rdv);
	void supprimerRdv(RDV *rdv);
	void afficherRdv();

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
	const list<RDV*>& getListeRdvs() const { return liste_rdvs; }
};

#endif
