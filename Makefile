CXX = g++
CXXFLAGS = -g -Wall -MMD -std=c++0x -O `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = Main.o Card.o Game.o Table.o Deck.o Player.o HumanPlayer.o ComputerPlayer.o GameController.o
VIEWS = GameWindowView.o TopMenuView.o CardTableView.o PlayerListView.o HandCardsView.o PlayerPickerView.o
# Card.o Command.o Deck.o Player.o Table.o Game.o GameController.o View.o HumanPlayer.o ComputerPlayer.o
CPP = ${OBJECTS:.o=.cpp} ${VIEWS:.o=.cpp}
HEADERS = ${OBJECTS:.o=.h} ${VIEWS:.o=.h}
DEPENDS = ${OBJECTS:.o=.d} ${VIEWS:.o=.d}
EXEC = straights
TESTSCRIPT = tester.sh

${EXEC}: ${OBJECTS} ${VIEWS}
	${CXX} ${OBJECTS} ${VIEWS} ${CXXFLAGS} -o ${EXEC}

clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${VIEWS} ${EXEC}

test:
	bash ./${TESTSCRIPT} ./${EXEC}

zip:
	zip straights.zip ${CPP} ${HEADERS} Makefile

-include ${DEPENDS}
