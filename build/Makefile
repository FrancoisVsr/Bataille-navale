PATH_SRC=../src/

all : bataille_naval

clean :
	del *.o

rebuild : clean all

bataille_naval : main.o
	g++ -o bataille_naval.exe main.o

main.o : $(PATH_SRC)main.cpp
	g++ -o main.o -c $(PATH_SRC)main.cpp