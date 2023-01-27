CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p08_main: p08_main.o alphabet.o nonTerminal.o grammar.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p08_main.o: p08_main.cc alphabet.h nonTerminal.h grammar.h
	$(CXX) -c p08_main.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) -c alphabet.cc

nonTerminal.o: nonTerminal.cc nonTerminal.h
	$(CXX) -c nonTerminal.cc

grammar.o: grammar.cc grammar.h
	$(CXX) -c grammar.c	c



clean:
	rm *.o output.gr p08_main