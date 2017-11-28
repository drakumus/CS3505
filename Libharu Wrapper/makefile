#Rohan Cheeniyil
#u0914584
#CS3505
#A2: Make File

CC=g++
CLAGS = -Wall -std=c11

LIBHARU = ../
LIBHARUSRC = $(LIBHARU)src
LIBHARUINCLUDE = $(LIBHARU)include

LIBS = -lhpdfs -lz
SRCS = spiralPDF spiralPDF.cpp spiral.cpp HaruPDF.cpp

#OBJS = $(SRCS:.cpp=.o)
#execute compiles here and links
MAIN = spiralPDF

spiralPDF: spiralPDF.cpp spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -o spiralPDF spiral.o HaruPDF.o spiralPDF.cpp -L$(LIBHARUSRC) -I./ -I$(LIBHARUINCLUDE) $(LIBS)

spiral.o: spiral.cpp spiral.h
	$(CC) $(CFLAGS) -c spiral.cpp -I./

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp -L$(LIBHARUSRC) -I./ -I$(LIBHARUINCLUDE) $(LIBS)

clean:
	rm spiralPDF *.o

#test
test: spiralPDF
	./spiralPDF "View fine me gone this name an rank. Compact greater and demands mrs the parlors. Park be fine easy am size away. Him and fine bred knew. At of hardly sister favour. As society explain country raising weather of. Sentiments nor everything off out uncommonly partiality bed."

#spiral: spiral.cpp
#	$(CC) $(CFLAGS) -o $(SRCS) -I$(LIBHARUINCLUDE) -I./ -L$(LIBHARUDIR) $(LIBS)

