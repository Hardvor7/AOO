#include "Entreprise.hpp"
#include "DateHeure.hpp"
#include "Etudiant.hpp"
#include "RDV.hpp"

list<Entreprise*> Entreprise::liste_entreprises;

Entreprise::Entreprise(const string& nom, const string& adresse, const string& nomContact, const string& telephoneContact)
{
	if (searchByNom(nom) != nullptr)
		throw invalid_argument( "Entreprise déjà existante" );

	this->nom = nom;
	this->adresse = adresse;
	this->nomContact = nomContact;
	this->telephoneContact = telephoneContact;

	liste_entreprises.push_back(this);
}

Entreprise* Entreprise::searchByNom(const string& nom)
{
	for (Entreprise *entreprise : liste_entreprises)
	{
		if (entreprise->nom == nom)
			return entreprise;
	}
	return nullptr;
}

void Entreprise::ajouterRdv(RDV *rdv)
{
	list<RDV*>::iterator it;
	for (it = liste_rdvs.begin(); it != liste_rdvs.end(); it++)
	{
		if ((*rdv) < (**it))
		{
			liste_rdvs.insert(it, rdv);
			return;
		}
	}

	liste_rdvs.push_back(rdv);
}

void Entreprise::supprimerRdv(RDV *rdv)
{
	liste_rdvs.remove(rdv);
}

void Entreprise::afficherRdv()
{
	int n = 1;
	cout << endl << "Nombre de rendez-vous: " << liste_rdvs.size() << endl;
	cout << "_________________________________________________________" << endl;
	cout << "|    |     Date     |    Heure    |       Etudiant      |" << endl;
	for(RDV *rdv : liste_rdvs)
	{
		string etudiant = rdv->getEtudiant()->getNom().c_str();
		etudiant += " ";
		etudiant += rdv->getEtudiant()->getPrenom().c_str();
		cout << "|----+--------------+-------------+---------------------|" << endl;
			printf("| %2d |  %10s  | %5s-%5s | %-20s|\n", n, rdv->getDate()->toString().c_str(), rdv->getHeureDebut()->toString().c_str(), rdv->getHeureFin()->toString().c_str(), etudiant.c_str());
		n++;
	}
	cout << "|____|______________|_____________|_____________________|" << endl;
}

