#include "RDV.hpp"
#include "DateHeure.hpp"
#include "Etudiant.hpp"
#include "Entreprise.hpp"

list<RDV*> RDV::liste_rdvs;

RDV::RDV(Date *date, Heure *heure_debut, Heure *heure_fin, Etudiant *etudiant, Entreprise *entreprise)
{

	if (*heure_fin <= *heure_debut)
		throw invalid_argument( "Un rendez-vous ne peut pas finir avant d'avoir commencé" );

	this->date = date;
	this->heure_debut = heure_debut;
	this->heure_fin = heure_fin;
	this->etudiant = etudiant;
	this->entreprise = entreprise;

	this->etudiant->ajouterRdv(this);
	this->entreprise->ajouterRdv(this);

	ajoutComparatifRDV();
}

void RDV::ajoutComparatifRDV()
{
	if (liste_rdvs.empty())
	{
		liste_rdvs.push_back(this);
		return;
	}

	list<RDV*>::iterator it;
	for (it = liste_rdvs.begin(); it != liste_rdvs.end(); it++)
	{
		if (chevauche(**it))
		{
			throw invalid_argument( "Chevauchement d'horaire" );
		}
		if ((*this) < (**it))
		{
			liste_rdvs.insert(it, this);
			return;
		}
	}

	liste_rdvs.push_back(this);
}

void RDV::afficher()
{
	cout << etudiant->getNom() << " " << etudiant->getPrenom() << " ---> " << entreprise->getNom() << endl;
	cout << "Date:" << date->toString();
	cout << "\t" << heure_debut->toString() << "-" << heure_fin->toString() << endl;
}

bool RDV::chevauche(RDV rdv)
{
	if (!(*date == *rdv.date))
		return false;
	if (*heure_debut >= *rdv.heure_fin)
		return false;
	if (*heure_fin <= *rdv.heure_debut)
		return false;
	return true;
}

bool RDV::operator<(RDV rdv)
{
	if (date < rdv.date)
		return true;
	if (date == rdv.date && heure_debut < rdv.heure_debut && heure_fin < rdv.heure_debut)
		return true;

	return false;
}	
