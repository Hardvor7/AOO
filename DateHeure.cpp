#include "DateHeure.hpp"

Date::Date(int jour, int mois, int annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
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

Heure::Heure(const Heure& h)
: Heure(h.heure, h.minute)
{ }

bool Heure::operator<(Heure h)
{
	if (heure != h.heure)
		return heure < h.heure;
	return minute < h.minute;
}

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

string Heure::toString()
{
	ostringstream h;
	h << heure << ":" << minute;
	return h.str();
}
