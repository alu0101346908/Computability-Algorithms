COMP = g++
COMPFLAGS = -std=c++17 -g -Wall

P3-main: P3-main.o alphabet.o string.o language.o calculator.o
	$(COMP) $(COMPFLAGS) -o $@ $^

alphabet.o: alphabet.cc alphabet.h
	$(COMP) -c alphabet.cc

string.o: string.cc string.h
	$(COMP) -c string.cc

language.o: language.cc language.h
	$(COMP) -c language.cc

calculator.o: calculator.cc calculator.h
	$(COMP) -c calculator.cc


P3-main.o: P3-main.cc alphabet.h string.h language.h calculator.h
	$(COMP) -c P3-main.cc

clean:
	rm *.o output.txt P3-main