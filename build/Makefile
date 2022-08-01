PATH_SRC=../src/

CC=g++

LDFLAGS=`sdl2-config --cflags --libs`
#LDFLAGS=`pkg-config --libs --cflags gtk+-2.0`

all : bataille_navale
#all: interface

clean :
	rm *.o

distclean : clean
	rm bataille_navale.exe

rebuild : clean all

#interface: $(PATH_SRC)gtk.c
#interface: $(PATH_SRC)interface.cpp
#	g++ $^ $(LDFLAGS)

bataille_navale : *.o
	$(CC) -o bataille_navale.exe *.o $(LDFLAGS)

*.o : $(PATH_SRC)*.cpp
	$(CC) -c $^ $(LDFLAGS)
