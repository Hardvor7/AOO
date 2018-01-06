#ifndef DATE_HEURE_HPP
#define DATE_HEURE_HPP

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

class Date
{
	int jour;
	int mois;
	int annee;

public:
	Date(int jour, int mois, int annee);
	Date(const string& d, int dateCondition = 0);
	Date(const Date& d);
	
	bool operator<(Date d);
	bool operator<=(Date d);
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
	Heure(string& heure);
	Heure(const Heure& h);
	
	bool operator==(Heure h);
	bool operator>(Heure h);
	bool operator>=(Heure h);
	bool operator<(Heure h);
	bool operator<=(Heure h);

	string toString();

	int getHeure() const { return heure; }
	int getMinute() const { return minute; }
};

#endif
