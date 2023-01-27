COMP = g++
COMPFLAGS = -std=c++17 -g -Wall

P1-main: P1-main.o alphabet.o string.o 
	$(COMP) $(COMPFLAGS) -o $@ $^

alphabet.o: alphabet.cc alphabet.h
	$(COMP) -c alphabet.cc

string.o: string.cc string.h
	$(COMP) -c string.cc

P1-main.o: P1-main.cc alphabet.h string.h
	$(COMP) -c P1-main.cc

clean:
	rm *.o output.txt P1-main