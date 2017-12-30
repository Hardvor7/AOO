#ifndef DIPLOME_HPP
#define DIPLOME_HPP

#include <string>

using namespace std;

class Etudiant;

class Diplome
{
	int code;
	string nom_national;
	string date_obtention;
	string lieu_obtention;
	Etudiant *etudiant;

public:
	Diplome(int code, const string& nom_national, const string& date_obtention, const string& lieu_obtention, Etudiant *etudiant);
	
	// Getters and Setters
	int getCode() const { return code; }
	const string& getNomNational() const { return nom_national; }
	const string& getDateObtention() const { return date_obtention; }
	const string& getLieuObtention() const { return lieu_obtention; }
	Etudiant* getEtudiant() const { return etudiant; }
};

#endif
