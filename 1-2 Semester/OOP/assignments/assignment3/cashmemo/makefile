all: main

main: main.o CashMemo.o Date.o SaleLine.o
	g++ -o main.exe main.o CashMemo.o Date.o SaleLine.o

main.o: main.cpp CashMemo.h Date.h SaleLine.h
	g++ -c main.cpp

CashMemo.o: CashMemo.cpp CashMemo.h Date.h SaleLine.h
	g++ -c CashMemo.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

SaleLine.o: SaleLine.cpp SaleLine.h
	g++ -c SaleLine.cpp

clean:
	del *.o main.exe