object = test.o libp_head.o
edit : $(object)
	g++ -o edit $(object) -lpcap

test.o : test.cpp libp_head.o
	g++ -c $< -std=c++11 -lpcap
libp_head.o : libp_head.cpp libp_head.h 
	g++ -c $< -std=c++11 -lpcap

.PHONY : clean
clean :
	rm edit $(objects) *.o
