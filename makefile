driver: listdriver.o
	g++ -o driver listdriver.o 
	
listdriver.o: main.cpp List.h List.cpp
	g++ -c main.cpp 
	

