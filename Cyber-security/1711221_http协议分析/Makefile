object = test.o 
edit : $(object)
	g++ -o edit $(object) -I ../Heads -std=c++11 -lpcap -lnids -lnet

test.o : http协议分析.cpp
	g++ -c $< -o $@ -I ../Heads -std=c++11 -lpcap -lnids -lnet

.PHONY : clean
clean :
	rm edit $(objects) *.o
