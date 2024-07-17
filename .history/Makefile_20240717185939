CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = dungeon.o asciiart.o blank.o main.o decorator.o chamber.o players.o enemies.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
valgrind: ${EXEC}				# run valgrind on the executable
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a4q2