CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p06_main: p06_main.o alphabet.o state.o automaton.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p06_main.o: p06_main.cc alphabet.h automaton.h state.h
	$(CXX) -c p06_main.cc

alphabet.o: alphabet.cc alphabet.h
	$(CXX) -c alphabet.cc

automaton.o: automaton.cc automaton.h
	$(CXX) -c automaton.cc

state.o: state.cc state.h
	$(CXX) -c state.cc


clean:
	rm *.o output.txt p06_main