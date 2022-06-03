PATH_SRC=../src/

all : bataille_naval

clean :
	del *.o

rebuild : clean all

bataille_naval : main.o joueur.o game.o plateau.o bateau.o case.o
	g++ -o bataille_naval.exe main.o game.o joueur.o plateau.o bateau.o case.o

main.o : $(PATH_SRC)main.cpp
	g++ -o main.o -c $(PATH_SRC)main.cpp

joueur.o : $(PATH_SRC)joueur.cpp
	g++ -o joueur.o -c $(PATH_SRC)joueur.cpp

game.o : $(PATH_SRC)game.cpp
	g++ -o game.o -c $(PATH_SRC)game.cpp

plateau.o : $(PATH_SRC)plateau.cpp
	g++ -o plateau.o -c $(PATH_SRC)plateau.cpp

bateau.o : $(PATH_SRC)bateau.cpp
	g++ -o bateau.o -c $(PATH_SRC)bateau.cpp

case.o : $(PATH_SRC)case.cpp
	g++ -o case.o -c $(PATH_SRC)case.cpp