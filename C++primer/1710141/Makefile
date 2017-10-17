object = usebrass2.o brass.o 
edit : $(object)
	g++ -std=c++11 -o  edit $(object)  

usebrass2.o : usebrass2.cpp brass.cpp brass.h
brass.o : brass.cpp brass.h


.PHONY : clean
clean :
	rm edit $(objects) *.o
