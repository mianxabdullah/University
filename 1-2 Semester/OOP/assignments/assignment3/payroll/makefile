all: main

main: main.o payroll.o employee.o officer.o daily_wager.o
	g++ -o main main.o payroll.o employee.o officer.o daily_wager.o

main.o: main.cpp payroll.h
	g++ -c main.cpp

payroll.o: payroll.cpp payroll.h officer.h daily_wager.h
	g++ -c payroll.cpp

employee.o: employee.cpp employee.h
	g++ -c employee.cpp

officer.o: officer.cpp officer.h
	g++ -c officer.cpp

daily_wager.o: daily_wager.cpp daily_wager.h
	g++ -c daily_wager.cpp

clean:
	del *.o main.exe