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

	ajoutComparatifRDV();

	this->etudiant->ajouterRdv(this);
	this->entreprise->ajouterRdv(this);

}

void RDV::supprimerRdv()
{
	etudiant->supprimerRdv(this);
	entreprise->supprimerRdv(this);
	liste_rdvs.remove(this);
	delete date;
	delete heureDebut;
	delete heureFin;
	delete this;
}

void RDV::ajoutComparatifRDV()
{
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

void RDV::afficherRdv()
{
	int n = 1;
	cout << endl << "Nombre de rendez-vous: " << liste_rdvs.size() << endl;
	cout << "_______________________________________________________________________" << endl;
	cout << "|    |     Date     |    Heure    |  Entrepise  |       Etudiant      |" << endl;
	for(RDV *rdv : liste_rdvs)
	{
		string etudiant = rdv->getEtudiant()->getNom().c_str();
		etudiant += " ";
		etudiant += rdv->getEtudiant()->getPrenom().c_str();
		cout << "|----+--------------+-------------+-------------+---------------------|" << endl;
			printf("| %2d |  %10s  | %5s-%5s | %-12s| %-20s|\n", n, rdv->getDate()->toString().c_str(), rdv->getHeureDebut()->toString().c_str(),
					rdv->getHeureFin()->toString().c_str(), rdv->getEntreprise()->getNom().c_str(), etudiant.c_str());
		n++;
	}
	cout << "|____|______________|_____________|_____________|_____________________|" << endl;
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
	if (*date < *rdv.date)
		return true;
	if (*date == *rdv.date && *heureDebut < *rdv.heureDebut && *heureFin < *rdv.heureDebut)
		return true;

	return false;
}	

// On ne compare pas les etudiants et les entreprises car les rendez-vous ont tous des horaires différents
bool RDV::operator==(RDV rdv)
{
	return (*date == *rdv.date && *heureDebut == *rdv.heureDebut && *heureFin == *rdv.heureFin);
}
