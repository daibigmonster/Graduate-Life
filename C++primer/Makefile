object = 1709281_vegnews.o 1709191_strngbad.o
edit : $(object)
	g++ -o edit $(object)

1709281_vegnews.o : 1709281_vegnews.cpp 1709191_strngbad.cpp 1709181_strngbad.h
1709191_strngbad.o : 1709191_strngbad.cpp 1709181_strngbad.h 

.PHONY : clean
clean :
	rm edit $(objects) *.o
