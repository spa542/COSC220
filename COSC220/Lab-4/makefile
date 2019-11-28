main: main.o payroll.o PayRollList.o
	g++ -std=c++11 main.o payroll.o PayRollList.o -o main

main.o: main.cpp payroll.cpp PayRollList.cpp
	g++ -std=c++11 -c main.cpp

PayRollList.o: PayRollList.cpp PayRollList.h
	g++ -std=c++11 -c PayRollList.cpp

payroll.o: payroll.cpp payroll.h
	g++ -std=c++11 -c payroll.cpp

