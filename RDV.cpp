#include "RDV.hpp"
#include "DateHeure.hpp"
#include "Etudiant.hpp"
#include "Entreprise.hpp"

list<RDV*> RDV::liste_rdvs;

RDV::RDV(Date *date, Heure *heureDebut, Heure *heureFin, Etudiant *etudiant, Entreprise *entreprise)
{
	if (*heureFin <= *heureDebut)
		throw invalid_argument( "Un rendez-vous ne peut pas finir avant d'avoir commencé" );

	this->date = date;
	this->heureDebut = heureDebut;
	this->heureFin = heureFin;
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
	cout << "\t" << heureDebut->toString() << "-" << heureFin->toString() << endl;
}

bool RDV::chevauche(RDV rdv)
{
	if (!(*date == *rdv.date))
		return false;
	if (*heureDebut >= *rdv.heureFin)
		return false;
	if (*heureFin <= *rdv.heureDebut)
		return false;
	return true;
}

bool RDV::operator<(RDV rdv)
{
	if (date < rdv.date)
		return true;
	if (date == rdv.date && heureDebut < rdv.heureDebut && heureFin < rdv.heureDebut)
		return true;

	return false;
}	
