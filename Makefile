all : prgm

clean :
	del *.o

rebuild : clean all

prgm : main.o
	g++ -o prgm.exe main.o

main.o : main.cpp
	g++ -o main.o -c main.cpp