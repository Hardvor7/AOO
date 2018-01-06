main: main.o diplome.o inscription.o experience.o rdv.o entreprise.o dateheure.o etudiant.o etudiantcycle1.o etudiantcycle2.o
	g++ -std=c++14 -o main main.o diplome.o inscription.o experience.o rdv.o entreprise.o dateheure.o etudiant.o etudiantcycle1.o etudiantcycle2.o

main.o: main.cpp 
	g++ -std=c++14 -c main.cpp

diplome.o: Diplome.cpp Diplome.hpp
	g++ -std=c++14 -c diplome.cpp

inscription.o: inscription.cpp inscription.hpp
	g++ -std=c++14 -c inscription.cpp

experience.o: Experience.cpp Experience.hpp
	g++ -std=c++14 -c experience.cpp

rdv.o: Rdv.cpp Rdv.hpp
	g++ -std=c++14 -c rdv.cpp

entreprise.o: Entreprise.cpp Entreprise.hpp
	g++ -std=c++14 -c entreprise.cpp

dateheure.o: DateHeure.cpp DateHeure.hpp
	g++ -std=c++14 -c DateHeure.cpp

etudiant.o: Etudiant.cpp Etudiant.hpp
	g++ -std=c++14 -c etudiant.cpp

etudiantcycle1.o: EtudiantCycle1.cpp EtudiantCycle1.hpp
	g++ -std=c++14 -c EtudiantCycle1.cpp

etudiantcycle2.o: EtudiantCycle2.cpp EtudiantCycle2.hpp
	g++ -std=c++14 -c EtudiantCycle2.cpp
	
clean:
	rm *.o main