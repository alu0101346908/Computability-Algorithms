CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p04_main: p04_main.o file.o variable.o loop.o comment.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p04_main.o: p04_main.cc file.h variable.h loop.h comment.h
	$(CXX) -c p04_main.cc

file.o: file.cc file.h
	$(CXX) -c file.cc

variable.o: variable.cc variable.h
	$(CXX) -c variable.cc

loop.o: loop.cc loop.h
	$(CXX) -c loop.cc

comment.o: comment.cc comment.h
	$(CXX) -c comment.cc
	
clean:
	rm *.o output.txt p04_main