object = test.o 
edit : $(object)
	g++ -o edit $(object) -lpcap

test.o : 1704151.c 
	g++ -c $< -o $@ -std=c++11 -lpcap

.PHONY : clean
clean :
	rm edit $(objects) *.o
