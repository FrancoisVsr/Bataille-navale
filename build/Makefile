PATH_SRC=../src/

CC=g++

LDFLAGS=`sdl2-config --cflags --libs`
#LDFLAGS=`pkg-config --libs --cflags gtk+-2.0`

all : bataille_navale interface

clean :
	rm *.o

distclean : clean
	rm bataille_navale.exe a.out

rebuild : clean all

#interface: $(PATH_SRC)gtk.c
interface: $(PATH_SRC)interface.c 
	gcc $^ $(LDFLAGS)

bataille_navale : *.o
	$(CC) -o bataille_navale.exe *.o

*.o : $(PATH_SRC)*.cpp
	$(CC) -c $^
