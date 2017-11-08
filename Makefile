$HEADERS = main.h RougeLike.h

default: full

full: main.cpp RougeLike.cpp ${HEADERS}
	g++ -c main.cpp RougeLike.cpp
	g++ main.o RougeLike.o -o ./bin/rlg -lncurses

clean: 
	 rm main.o RougeLike.o
