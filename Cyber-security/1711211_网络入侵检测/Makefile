object = test.o 
edit : $(object)
	gcc -o edit $(object) -lpcap -lnids -lnet

test.o : 1711121_检验入侵攻击的例子.c
	gcc -c $< -o $@ -lpcap -lnids -lnet

.PHONY : clean
clean :
	rm edit $(objects) *.o
