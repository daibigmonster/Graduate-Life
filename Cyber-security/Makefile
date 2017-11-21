object = test.o 
edit : $(object)
	g++ -o edit $(object) -lpcap -lnid -lnet

test.o : 1711121_检验入侵攻击的例子.cpp
	g++ -c $< -o $@ -std=c++11 -lpcap

.PHONY : clean
clean :
	rm edit $(objects) *.o
