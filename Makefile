CXX = g++
CXXFLAGS = -g -Wall -MMD -std=c++0x
OBJECTS = Card.o Command.o
CPP = ${OBJECTS:.o=.cpp}
HEADERS = ${OBJECTS:.o=.h}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = Straights
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
