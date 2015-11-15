CC = gcc
VPATH  = ./inc ./src
SRC    = ./src
INC    = ./inc
CFLAGS = -std=c99 -I${INC} -Ofast -Wall

EXEC = TextAlign_t2b TextAlign_b2b TextRealChar

all: ${EXEC}

TextAlign_t2b: TextAlign_t2b.c liberrmsg.o liberrmsg.h
	${CC} -o TextAlign_t2b ${SRC}/TextAlign_t2b.c liberrmsg.o  -Ofast -Wall ${CFLAGS}

TextAlign_b2b: TextAlign_b2b.c liberrmsg.o liberrmsg.h
	${CC} -o TextAlign_b2b ${SRC}/TextAlign_b2b.c liberrmsg.o  -Ofast -Wall ${CFLAGS}

TextRealChar: TextRealChar.c liberrmsg.o liberrmsg.h
	${CC} -o TextRealChar ${SRC}/TextRealChar.c liberrmsg.o    -Ofast -Wall ${CFLAGS}

install:
	mv ${EXEC} bin
	rm *.o -rf

clean:
	rm -f *.o bin/* ${EXEC} -rf