<<<<<<< HEAD
object = test.o 
edit : $(object)
	g++ -o edit $(object) -lpcap

test.o : 1711121_检验入侵攻击的例子.cpp
	g++ -c $< -o $@ -std=c++11 -lpcap

.PHONY : clean
clean :
	rm edit $(objects) *.o
=======
object = test.o 
edit : $(object)
	g++ -o edit $(object) -lpcap -lnids -lnet

test.o : 1704251_show_tcp_data.c 
	g++ -c $< -o $@ -std=c++11 -lpcap -lnids -lnet

.PHONY : clean
clean :
	rm edit $(objects) *.o
>>>>>>> 24241f6e31f801c718ba246c62f778d56f606eee
