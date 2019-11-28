StudentDB: main.o StudentDB.o Courses.o Student.o 
	g++ -o StudentDB -std=c++11 main.o Courses.o StudentDB.o Student.o
main.o: main.cpp Courses.h Student.h StudentDB.h
	g++ -c -std=c++11 main.cpp
StudentDB.o: StudentDB.cpp Student.h StudentDB.h Courses.h
	g++ -c -std=c++11 StudentDB.cpp
Student.o: Student.cpp Student.h Courses.h
	g++ -c -std=c++11 Student.cpp
Courses.o: Courses.cpp Courses.h
	g++ -c -std=c++11 Courses.cpp
clean:
	rm main.o StudentDB.o Courses.o Student.o StudentDB