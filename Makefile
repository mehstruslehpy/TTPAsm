all: main

main: common.h ttpasm.cpp clean.o buildmap.o replace.o write.o
	g++ -g -Wall -pedantic ttpasm.cpp clean.o buildmap.o replace.o write.o -o asm

clean.o: clean.cpp clean.h
	g++ -g -Wall -pedantic clean.cpp -o clean.o -c
buildmap.o: buildmap.cpp buildmap.h
	g++ -g -Wall -pedantic buildmap.cpp -o buildmap.o -c
replace.o: replace.cpp replace.h
	g++ -g -Wall -pedantic replace.cpp -o replace.o -c
write.o: write.cpp write.h
	g++ -g -Wall -pedantic write.cpp -o write.o -c

clean:
	rm *.o
	rm asm
