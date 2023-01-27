CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p11_main: p11_main.o  currency.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p11_main.o: p11_main.cc currency.h
	$(CXX) -c p11_main.cc

currency.o: currency.cc currency.h
	$(CXX) -c currency.cc	



clean:
	rm *.o p11_main