output: main.o matrix.o
		g++ main.o matrix.o -o matrix

main.o: main.cpp
		g++ -c main.cpp

matrix.o: matrix.cpp matrix.hpp main.o
		g++ -c matrix.cpp

clean:
		rm *.o matrix 