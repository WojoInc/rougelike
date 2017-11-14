$HEADERS = main.h RougeLike.h PC.h Floor.h

default: full

full: main.cpp PC.cpp RougeLike.cpp Floor.cpp ${HEADERS}
	g++ -c main.cpp RougeLike.cpp PC.cpp Floor.cpp
	g++ main.o RougeLike.o PC.o Floor.o -o ./bin/rlg -lncurses -Wall

clean: 
	 rm main.o RougeLike.o PC.o Floor.o
