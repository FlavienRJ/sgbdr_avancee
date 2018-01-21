#
##

CC	=	gcc 
CFLAGS	=  	-Wall
CFLAGS  += 	-DDEBUG -D_GNU_SOURCE
CFLAGS  += 	-g
CFLAGS  += 	-w

PREFIX ?= 	${DESTDIR}/usr
LIBDIR	=	${PREFIX}/lib
INCDIR	=	${PREFIX}/include 
LIBS    =       -lm

CIBLES	=	main

all: $(CIBLES)

clean: 
	$(RM) -f core *.o $(CIBLES) *~


main: main.o indexation.o iohelper.o journalisation.o nuplet_helper.o operateurs.o parser.o relation_helper.o
	$(CC) $(CFLAGS) -o $@ main.o indexation.o iohelper.o journalisation.o nuplet_helper.o operateurs.o parser.o relation_helper.o $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c indexation.h iohelper.h journalisation.h nuplet_helper.h operateurs.h parser.h relation_helper.h sgbd.h

indexation.o: indexation.c
	$(CC) $(CFLAGS) -c indexation.c
		
iohelper.o: iohelper.c
	$(CC) $(CFLAGS) -c iohelper.c
	
journalisation.o: journalisation.c
	$(CC) $(CFLAGS) -c journalisation.c
	
nuplet_helper.o: nuplet_helper.c
	$(CC) $(CFLAGS) -c nuplet_helper.c
	
operateurs.o: operateurs.c
	$(CC) $(CFLAGS) -c operateurs.c
	
parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c
	
relation_helper.o: relation_helper.c
	$(CC) $(CFLAGS) -c relation_helper.c
	

run: clean main	
		./main
