$HEADERS = main.h RougeLike.h PC.h

default: full

full: main.cpp PC.cpp RougeLike.cpp ${HEADERS}
	g++ -c main.cpp RougeLike.cpp PC.cpp
	g++ main.o RougeLike.o PC.o -o ./bin/rlg -lncurses -Wall

clean: 
	 rm main.o RougeLike.o PC.o
