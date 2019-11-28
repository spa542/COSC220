main: main.o HanoiStack.o Disk.o
	g++ -o main main.o HanoiStack.o Disk.o -std=c++11
main.o: main.cpp HanoiStack.h Disk.h
	g++ -c main.cpp -std=c++11
HanoiStack.o: HanoiStack.cpp HanoiStack.h
	g++ -c HanoiStack.cpp -std=c++11
Disk.o: Disk.cpp Disk.h
	g++ -c Disk.cpp -std=c++11
clean:
	rm -f *.o main
