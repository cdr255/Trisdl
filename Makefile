OBJS = main.o
CXX = g++
CFLAGS = -c -Wall
LIBS = -lSDL -lSDL_image -lSDL_ttf
LFLAGS = -Wall ${LIBS}

trisdl: ${OBJS}
	${CXX} ${LFLAGS} ${OBJS} -o trisdl

main.o: main.cpp main.h SURGE.h
	${CXX} ${CFLAGS} main.cpp -o main.o

clean:
	rm -rfv *~ *.o trisdl

