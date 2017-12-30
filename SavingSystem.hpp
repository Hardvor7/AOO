#ifndef SAVINGSYSTEM_HPP
#define SAVINGSYSTEM_HPP

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

class SavingSystem {

public:
	static void saveEtudiants();
	static void restoreEtudiants();

	static void saveEntreprises();
	static void restoreEntreprises();
};

#endif
