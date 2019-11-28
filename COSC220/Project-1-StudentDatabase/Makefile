main: main.o student.o course.o StudentDB.o
	g++ -std=c++11 main.o student.o course.o StudentDB.o -o main

main.o: main.cpp student.cpp course.cpp StudentDB.cpp
	g++ -std=c++11 -c main.cpp

student.o: student.cpp student.h
	g++ -std=c++11 -c student.cpp

course.o: course.cpp course.h
	g++ -std=c++11 -c course.cpp

StudentDB.o: StudentDB.cpp StudentDB.h
	g++ -std=c++11 -c StudentDB.cpp

clean:
	rm -f *.o main
