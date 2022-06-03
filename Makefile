all : prgm

clean :
	del *.o

rebuild : clean all

prgm : main.o joueur.o game.o plateau.o bateau.o case.o
	g++ -o prgm.exe main.o game.o joueur.o plateau.o bateau.o case.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

joueur.o : joueur.cpp
	g++ -o joueur.o -c joueur.cpp

game.o : game.cpp
	g++ -o game.o -c game.cpp

plateau.o : plateau.cpp
	g++ -o plateau.o -c plateau.cpp

bateau.o : bateau.cpp
	g++ -o bateau.o -c bateau.cpp

case.o : case.cpp
	g++ -o case.o -c case.cpp