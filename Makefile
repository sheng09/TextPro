CC = gcc
CFLAGS = -std=c99 -I/home/sheng/ProgramSheng/Mylib/Seismic-Field-Works/include -L/home/sheng/ProgramSheng/Mylib/Seismic-Field-Works/lib
VPATH  = /home/sheng/ProgramSheng/Mylib/Seismic-Field-Works/include ./src
SRC    = ./src

EXEC = TextAlign_t2b TextAlign_b2b TextRealChar

all: ${EXEC}

TextAlign_t2b: TextAlign_t2b.c liberrmsg.h
	${CC} -o TextAlign_t2b ${SRC}/TextAlign_t2b.c  -lerrmsg -Ofast -Wall ${CFLAGS}

TextAlign_b2b: TextAlign_b2b.c liberrmsg.h
	${CC} -o TextAlign_b2b ${SRC}/TextAlign_b2b.c  -lerrmsg -Ofast -Wall ${CFLAGS}

TextRealChar: TextRealChar.c
	${CC} -o TextRealChar ${SRC}/TextRealChar.c    -lerrmsg -Ofast -Wall ${CFLAGS}

install:
	mv ${EXEC} bin

clean:
	rm -f *.o bin/* ${EXEC} -rf