logicielREE: main.o Diplome.o Inscription.o Experience.o RDV.o Entreprise.o DateHeure.o Etudiant.o EtudiantCycle1.o EtudiantCycle2.o
	g++ -std=c++14 -o logicielREE main.o Diplome.o Inscription.o Experience.o RDV.o Entreprise.o DateHeure.o Etudiant.o EtudiantCycle1.o EtudiantCycle2.o

main.o: main.cpp 
	g++ -std=c++14 -c main.cpp

Diplome.o: Diplome.cpp Diplome.hpp
	g++ -std=c++14 -c Diplome.cpp

Inscription.o: Inscription.cpp Inscription.hpp
	g++ -std=c++14 -c Inscription.cpp

Experience.o: Experience.cpp Experience.hpp
	g++ -std=c++14 -c Experience.cpp

RDV.o: RDV.cpp RDV.hpp
	g++ -std=c++14 -c RDV.cpp

Entreprise.o: Entreprise.cpp Entreprise.hpp
	g++ -std=c++14 -c Entreprise.cpp

DateHeure.o: DateHeure.cpp DateHeure.hpp
	g++ -std=c++14 -c DateHeure.cpp

Etudiant.o: Etudiant.cpp Etudiant.hpp
	g++ -std=c++14 -c Etudiant.cpp

EtudiantCycle1.o: EtudiantCycle1.cpp EtudiantCycle1.hpp
	g++ -std=c++14 -c EtudiantCycle1.cpp

EtudiantCycle2.o: EtudiantCycle2.cpp EtudiantCycle2.hpp
	g++ -std=c++14 -c EtudiantCycle2.cpp
	
clean:
	rm *.o logicielREE
	
