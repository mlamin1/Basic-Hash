run: main.o
	g++ -o run main.o

main.o:	main.cpp
	g++ -Wall -c -g -std=c++11 main.cpp

clean:
	rm -f run main.o

rebuild:
	make clean
	make
