object = test.o 
edit : $(object)
	g++ -o edit $(object) -lpcap -lnids -lnet

test.o : 1704251_show_tcp_data.c 
	g++ -c $< -o $@ -std=c++11 -lpcap -lnids -lnet

.PHONY : clean
clean :
	rm edit $(objects) *.o
