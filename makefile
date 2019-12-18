CC=gcc
AR=ar

FLAGS= -Wall -g

all: txtfind  libmylib.a isort libmylibb.a

txtfind: txtfindmain.o txtfind_c.o libmylib.a
	$(CC) $(FLAGS) -o txtfind libmylib.a txtfind_c.o txtfindmain.o

libmylib.a: txtfind_c.o
	$(AR) -rcs libmylib.a txtfind_c.o txtfind_c.h	
txtfind_c.o: txtfind_c.c txtfind_c.h  
	$(CC) $(FLAGS) -c txtfind_c.c 
txtfindmain.o: txtfindmain.c txtfind_c.h 
	$(CC) $(FLAGS) -c txtfindmain.c


isort: mainS.o Sorting.o libmylibb.a
	$(CC) $(FLAGS) -o isort libmylibb.a mainS.o Sorting.o

libmylibb.a: Sorting.o
	$(AR) -rcs libmylibb.a Sorting.o Sorting.h	
Sorting.o: Sorting.c Sorting.h  
	$(CC) $(FLAGS) -c Sorting.c 
mainS.o: mainS.c Sorting.h 
	$(CC) $(FLAGS) -c mainS.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so .out isort txtfind
