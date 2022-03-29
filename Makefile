# Files
SRC_FILES = $^
TESTS_FILES = $(wildcard ./tests/*.cpp)

# Variables
OBJS = traversals.o parser.o graph.o pagerank.o kosaraju.o
TESTS = parser_test.o graph_test.o traversals_test.o kosaraju_test.o
INCLUDES = parser.h graph.h traversals.h pagerank.h kosaraju.h

# Arguments
CXX = clang++	
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++	
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Build objects and main
main: main.o ${OBJS}
	${LD} main.o ${OBJS} ${LDFLAGS} -o main

.cpp.o:
	${CXX} ${CXXFLAGS} ${SRC_FILES}

# Build and run tests
parser_test: parser_test.o ${OBJS}
	${LD} ${LDFLAGS} parser_test.o ${OBJS} -o parser_test

parser_test.o: tests/parser_test.cpp tests/catch.hpp ${INCLUDES}
	${CXX} ${CXXFLAGS} ./tests/parser_test.cpp

graph_test: graph_test.o ${OBJS}
	${LD} ${LDFLAGS} graph_test.o ${OBJS} -o graph_test

graph_test.o: tests/graph_test.cpp tests/catch.hpp ${INCLUDES}
	${CXX} ${CXXFLAGS} ./tests/graph_test.cpp

traversals_test: traversals_test.o ${OBJS}
	${LD} ${LDFLAGS} traversals_test.o ${OBJS} -o traversals_test

traversals_test.o: tests/traversals_test.cpp tests/catch.hpp ${INCLUDES}
	${CXX} ${CXXFLAGS} ./tests/traversals_test.cpp

pagerank_test: pagerank_test.o ${OBJS}
	${LD} ${LDFLAGS} pagerank_test.o ${OBJS} -o pagerank_test

pagerank_test.o: tests/pagerank_test.cpp tests/catch.hpp ${INCLUDES}
	${CXX} ${CXXFLAGS} ./tests/pagerank_test.cpp

kosaraju_test: kosaraju_test.o ${OBJS}
	${LD} ${LDFLAGS} kosaraju_test.o ${OBJS} -o kosaraju_test

kosaraju_test.o: tests/kosaraju_test.cpp tests/catch.hpp ${INCLUDES}
	${CXX} ${CXXFLAGS} ./tests/kosaraju_test.cpp

# Clean run files in the directory
EXECUTABLE = main parser_test graph_test traversals_test pagerank_test kosaraju_test
clean:
	rm -f $(EXECUTABLE) *.o