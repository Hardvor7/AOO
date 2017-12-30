#ifndef DATE_HEURE_HPP
#define DATE_HEURE_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
	int jour;
	int mois;
	int annee;

public:
	Date(int jour, int mois, int annee);
	Date(const Date& d);
	
	bool operator<(Date d);
	bool operator==(Date d);
	string toString();

	int getJour() const { return jour; }
	int getMois() const { return mois; }
	int getAnnee() const { return annee; }
};

class Heure
{
	int heure;
	int minute;

public:
	Heure(int heure, int minute);
	Heure(const Heure& h);
	
	bool operator<(Heure h);
	bool operator==(Heure h);
	bool operator>(Heure h);

	string toString();

	int getHeure() const { return heure; }
	int getMinute() const { return minute; }
};

#endif
