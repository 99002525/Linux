
    
TARGET = all.out
$(TARGET): test.c myutils.c mystring.c bitmask.c
	 gcc test.c myutils.c mystring.c bitmask.c -o all.out
test.o: test.c mystring.h myutils.h bitmask.h
	gcc -c test.c


myutils.o: myutils.c myutils.h 
	gcc -c myutils.c


mystring.o: mystring.c mystring.h
	gcc -c mystring.c


bitmask.o: bitmask.c bitmask.h
	gcc -c bitmask.c
clean:
	rm *.o *.out





