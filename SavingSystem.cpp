#include "SavingSystem.hpp"
#include "EtudiantCycle1.hpp"
#include "EtudiantCycle2.hpp"
#include "Entreprise.hpp"
#include "RDV.hpp"

// Method split from : http://www.cplusplus.com/articles/2wA0RXSz/
const vector<string> split(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;

	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);

	return v;
}

void SavingSystem::saveEtudiants()
{
	ofstream saveFile;
	saveFile.open ("data/etudiants.dat", ios::trunc);
	for (Etudiant *etudiant : Etudiant::getEtudiants())
	{
		cout << "Saving Etudiant " << etudiant->getNumero() << endl;
		int cycle = 0;
		if (etudiant->getClassType() == ETUDIANT_CYCLE1_TYPE)
		{
			cycle = 1;
			saveFile << "CYCLE1" << ":";
		}
		if (etudiant->getClassType() == ETUDIANT_CYCLE2_TYPE)
		{
			cycle = 2;
			saveFile << "CYCLE2" << ":";
		}

		saveFile << etudiant->getNumero() << ":";
		saveFile << etudiant->getNom() << ":";
		saveFile << etudiant->getPrenom() << ":";
		saveFile << etudiant->getAdresse() << ":";
		saveFile << etudiant->getTelephone() << ":";

		if (cycle == 1)
		{
			saveFile << ((EtudiantCycle1*)etudiant)->getAnneeBac() << ":";
			saveFile << ((EtudiantCycle1*)etudiant)->getLieuBac() << ":";
			saveFile << ((EtudiantCycle1*)etudiant)->getSerieBac() << ":";
		}

		if (cycle == 2)
		{
			saveFile << ((EtudiantCycle2*)etudiant)->getDiscipline() << ":";
		}

		saveFile << "\n";
		cout << "Done..." << endl;
	}
	saveFile.close();
}

void SavingSystem::restoreEtudiants()
{
	string line;
	ifstream saveFile;
	saveFile.open ("data/etudiants.dat");
	while(!saveFile.eof())
	{
		getline(saveFile, line);
		if (line == "")
			return;
		cout << "Ligne: " << line << endl;

		vector<string> datas = split(line, ':');
		if (datas[0] == "CYCLE1")
			new EtudiantCycle1(atoi(datas[1].c_str()), datas[2], datas[3], datas[4], datas[5], datas[6], datas[7], datas[8]);

		if (datas[0] == "CYCLE2")
			new EtudiantCycle2(atoi(datas[1].c_str()), datas[2], datas[3], datas[4], datas[5], datas[6]);
	}
	saveFile.close();
}

void SavingSystem::saveEntreprises()
{
	ofstream saveFile;
	saveFile.open ("data/entreprises.dat", ios::trunc);
	for (Entreprise *entreprise : Entreprise::getEntreprises())
	{
		cout << "Saving Entreprise  " << entreprise->getNom() << endl;
		saveFile << entreprise->getNom() << ":";
		saveFile << entreprise->getAdresse() << ":";
		saveFile << entreprise->getNomContact() << ":";
		saveFile << entreprise->getNomContact() << ":";
		//saveFile << "{";
		//saveFile << "}:";
		saveFile << "\n";
		cout << "Done..." << endl;
	}
	saveFile.close();
}
