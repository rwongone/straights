CXX = g++
CXXFLAGS = -g -Wall -MMD -std=c++0x
OBJECTS = Main.o Card.o Command.o Deck.o Player.o Table.o Game.o GameController.o View.o HumanPlayer.o ComputerPlayer.o
CPP = ${OBJECTS:.o=.cpp}
HEADERS = ${OBJECTS:.o=.h}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights.out
TESTSCRIPT = tester.sh

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

test:
	bash ./${TESTSCRIPT} ./${EXEC}

zip:
	zip straights.zip ${CPP} ${HEADERS} Makefile

-include ${DEPENDS}
