#ifndef DIPLOME_HPP
#define DIPLOME_HPP

#include <stdexcept>
#include <string>
#include <list>

using namespace std;

class Etudiant;
class Date;

class Diplome
{
	static list<Diplome*> liste_diplomes;

	int code;
	string nom_national;
	Date* date_obtention;
	string lieu_obtention;
	Etudiant *etudiant;

public:
	Diplome(int code, const string& nom_national, Date *date_obtention, const string& lieu_obtention, Etudiant *etudiant);

	static Diplome* searchByCode(int code);
	
	// Getters and Setters
	static list<Diplome*>& getDiplomes() { return liste_diplomes; }

	int getCode() const { return code; }
	const string& getNomNational() const { return nom_national; }
	Date* getDateObtention() const { return date_obtention; }
	const string& getLieuObtention() const { return lieu_obtention; }
	Etudiant* getEtudiant() const { return etudiant; }
};

#endif
