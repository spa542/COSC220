main: main.o Employee.o Executive.o Hourly.o
	g++ -o main -std=c++11 main.o Employee.o Executive.o Hourly.o
main.o: main.cpp Employee.cpp Executive.cpp Hourly.cpp
	g++ -c main.cpp -std=c++11
Employee.o: Employee.h Employee.cpp Hourly.h Hourly.cpp Executive.cpp Executive.h
	g++ -c Employee.cpp -std=c++11
Hourly.o: Hourly.cpp Hourly.h
	g++ -c Hourly.cpp -std=c++11
Executive.o: Executive.h Executive.cpp
	g++ -c Executive.cpp -std=c++11
clean:
	rm -f *.o main
