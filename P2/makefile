COMP = g++
COMPFLAGS = -std=c++17 -g -Wall

P2-main: P2-main.o alphabet.o string.o language.o
	$(COMP) $(COMPFLAGS) -o $@ $^

alphabet.o: alphabet.cc alphabet.h
	$(COMP) -c alphabet.cc

string.o: string.cc string.h
	$(COMP) -c string.cc

language.o: language.cc language.h
	$(COMP) -c language.cc


P2-main.o: P2-main.cc alphabet.h string.h language.h
	$(COMP) -c P2-main.cc

clean:
	rm *.o output.txt P2-main