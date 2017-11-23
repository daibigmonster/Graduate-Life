object = usebrass2.o brass.o 
edit : $(object)
	g++  -o  edit $(object)  

usebrass2.o : usebrass2.cpp brass.o
	g++ -c usebrass2.cpp -std=c++11
brass.o : brass.cpp brass.h
	g++  -c brass.cpp -std=c++11


.PHONY : clean
clean :
	rm edit $(objects) *.o
