CXX = g++
CXXFLAGS = -g -Wall -MMD -std=c++0x -O `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = Main.o GameWindowView.o TopMenuView.o CardTableView.o
CPP = ${OBJECTS:.o=.cpp}
HEADERS = ${OBJECTS:.o=.h}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights
TESTSCRIPT = tester.sh

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

test:
	bash ./${TESTSCRIPT} ./${EXEC}

zip:
	zip straights.zip ${CPP} ${HEADERS} Makefile

-include ${DEPENDS}
