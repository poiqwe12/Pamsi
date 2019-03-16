CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: ./pamsi
	./pamsi


./pamsi: main.o dane.o
	g++  ${CXXFLAGS} main.o dane.o

main.o: main.cpp dane.hh
	g++  ${CXXFLAGS} main.cpp

dane.o: dane.hh dane.cpp
	g++  ${CXXFLAGS} dane.cpp


clean:
	rm -f *.o ./pamsi



