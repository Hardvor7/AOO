#include "DateHeure.hpp"

Date::Date(int jour, int mois, int annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
}

Date::Date(const string& d, int dateCondition) // condition 1 : la date doit etre superieur a la date d'aujourdhui | 2 : la date doit etre inferieur a la date d'aujourdhui
{
	string date = d;
	string infos[3];
	date += "/";
	for(int i = 0; i < 3; i++)
	{
		int pos = date.find("/");
		int value = atoi(date.substr(0, pos).c_str());
		switch (i)
		{
			case 0:
				if (value < 1 || value > 31)
					throw invalid_argument( "Jour incorrect" );
				jour = value;
				break;
			case 1:
				if (value < 1 || value > 12)
					throw invalid_argument( "Mois incorrect" );
				mois = value;
				break;
			case 2:
				switch (dateCondition)
				{
				case 1:
					if (value < 2018)
						throw invalid_argument( "Année incorrect" );
					break;

				case 2:
					if (value > 2017)
						throw invalid_argument( "Année incorrect" );
					break;
				}
				annee = value;
				break;

		}
		date.erase(0, pos + 1);
	}
}

Date::Date(const Date& d)
: Date(d.jour, d.mois, d.annee)
{ }

bool Date::operator<(Date d)
{
	if (annee != d.annee)
		return annee < d.annee;
	if (mois != d.mois)
		return mois < d.mois;
	return jour < d.jour;
}

bool Date::operator<=(Date d)
{
	if (annee != d.annee)
		return annee < d.annee;
	if (mois != d.mois)
		return mois < d.mois;
	return jour <= d.jour;
}

bool Date::operator==(Date d)
{
	return (annee == d.annee && mois == d.mois && jour == d.jour);
}

string Date::toString()
{
	ostringstream date;
	date << jour << "/" << mois << "/" << annee;
	return date.str();
}



Heure::Heure(int heure, int minute)
{
	this->heure = heure;
	this->minute = minute;
}
Heure::Heure(string& heure)
{
	int pos = heure.find(":");
	int value = atoi(heure.substr(0, pos).c_str());
	if (value < 0 || value > 23)
		throw invalid_argument( "Heure incorrect" );

	this->heure = value;
	heure.erase(0, pos + 1);

	value = atoi(heure.c_str());
	if (value < 0 || value > 59)
		throw invalid_argument( "Minute incorrect" );

	this->minute = value;
}

Heure::Heure(const Heure& h)
: Heure(h.heure, h.minute)
{ }


bool Heure::operator==(Heure h)
{
	return (heure == h.heure && minute == h.minute);
}

bool Heure::operator>(Heure h)
{
	if (heure != h.heure)
		return heure > h.heure;
	return minute > h.minute;
}

bool Heure::operator>=(Heure h)
{
	if (heure != h.heure)
		return heure > h.heure;
	return minute >= h.minute;
}

bool Heure::operator<(Heure h)
{
	if (heure != h.heure)
		return heure < h.heure;
	return minute < h.minute;
}

bool Heure::operator<=(Heure h)
{
	if (heure != h.heure)
		return heure < h.heure;
	return minute <= h.minute;
}

string Heure::toString()
{
	char buffer [5];
	sprintf (buffer, "%02dh%02d", heure, minute);
	string h(buffer);
	return h;
}
