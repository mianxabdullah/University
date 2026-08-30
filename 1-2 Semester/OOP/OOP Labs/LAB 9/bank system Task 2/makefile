main2.exe: main2.obj bank.obj
	link main2.obj bank.obj
main2.obj: main2.cpp
	cl /c main2.cpp
bank.obj: bank.cpp
	cl /c bank.cpp
main2.cpp: bank.h
bank.cpp: bank.h