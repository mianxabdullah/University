main1.exe: main1.obj sms.obj
	link main1.obj sms.obj
main1.obj: main1.cpp
	cl /c main1.cpp
sms.obj: sms.cpp
	cl /c sms.cpp
main1.cpp: Sms.h
sms.cpp: Sms.h