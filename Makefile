CXX = g++
CXXFLAGS = -g -Wall -MMD -std=c++0x -O `pkg-config gtkmm-2.4 --cflags --libs`

# Main
OBJECTS = Main.o

# Model Classes
OBJECTS += Card.o Table.o Deck.o Player.o HumanPlayer.o ComputerPlayer.o

# Model Facade
OBJECTS += Game.o Subject.o

# Controllers
OBJECTS += GameController.o

# Views
OBJECTS += Observer.o GameWindowView.o TopMenuView.o CardTableView.o PlayerListView.o HandCardsView.o PlayerPickerView.o RoundSummaryView.o

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
	mkdir straightsgame && cp -R ${CPP} ${HEADERS} Makefile bonus.txt img straightsgame/ && zip -R straights.zip straightsgame/* straightsgame/img/* && rm -rf straightsgame

-include ${DEPENDS}
