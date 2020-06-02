#  CXX=clang++
CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

# CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = lab04Test01 lab04Test02 lab04Test03 lab04Test04

all: ${BINARIES}

lab04Test01: lab04Test01.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab04Test02: lab04Test02.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab04Test03: lab04Test03.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab04Test04: lab04Test04.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab04Test01
	./lab04Test02
	./lab04Test03
	./lab04Test04

clean:
	/bin/rm -f ${BINARIES} *.o
