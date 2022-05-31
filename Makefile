all : bataille_navale

rebuild : clean all

bataille_navale : main.o case.o plateau.o #loup.o lion.o ours.o attaque.o
	g++ -o bataille_navale main.o case.o plateau.o
	del *.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

case.o : case.cpp 
	g++ -o case.o -c case.cpp

plateau.o : plateau.cpp 
	g++ -o plateau.o -c plateau.cpp

clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP8.exe