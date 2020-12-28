main: main.o payroll.o
	g++ -std=c++11 -o main main.o payroll.o
main.o: main.cpp MyStack.h payroll.h
	g++ -std=c++11 -c main.cpp
payroll.o: payroll.h payroll.cpp
	g++ -std=c++11 -c payroll.cpp
clean:
	rm -f *.o main
