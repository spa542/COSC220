main: main.o payroll.o PayRollStack.o
	g++ -std=c++11 main.o payroll.o PayRollStack.o -o main

main.o: main.cpp payroll.cpp PayRollStack.cpp
	g++ -std=c++11 -c main.cpp

PayRollStack.o: PayRollStack.cpp PayRollStack.h
	g++ -std=c++11 -c PayRollStack.cpp

payroll.o: payroll.cpp payroll.h
	g++ -std=c++11 -c payroll.cpp

clean:
	rm -f *.o main

