SRC_FILES = $(wildcard *.cpp)

all : prgm

clean :
	del *.o

rebuild : clean all

prgm : *.o
	g++ -o prgm.exe *.o

*.o : *.cpp
	g++ -c $(SRC_FILES)