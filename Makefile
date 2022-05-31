all : prgm

clean :
	del *.o

rebuild : clean all

prgm : main.o game.o
	g++ -o prgm.exe main.o game.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

game.o : game.cpp
	g++ -o game.o -c game.cpp