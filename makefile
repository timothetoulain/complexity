all : main
Machine.o : Machine.cpp Machine.h 
	g++ -c Machine.cpp 
functions.o : functions.cpp functions.h
	g++ -c functions.cpp
main.o : Machine.h main.cpp functions.h
	g++ -c main.cpp
main : Machine.o main.o functions.o
	g++ -o main main.o Machine.o functions.o
clean :
	rm -rf *.o 