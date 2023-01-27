CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p07_main: p07_main.o alphabet.o automaton.o state.o nonTerminal.o grammar.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p07_main.o: p07_main.cc alphabet.h automaton.h state.h nonTerminal.h grammar.h
	$(CXX) -c p07_main.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) -c alphabet.cc

automaton.o: automaton.cc automaton.h
	$(CXX) -c automaton.cc

state.o: state.cc state.h
	$(CXX) -c state.cc

nonTerminal.o: nonTerminal.cc nonTerminal.h
	$(CXX) -c nonTerminal.cc

grammar.o: grammar.cc grammar.h
	$(CXX) -c grammar.cc



clean:
	rm *.o output.gr p07_main