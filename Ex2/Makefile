CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECTS_LIB = my_mat.o

all: libmymat.a connections

connections: $(OBJECTS_MAIN) libmymat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) libmymat.a

libmymat.a: my_mat.o
	$(AR) libmymat.a $(OBJECTS_LIB)

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o *.a *.so connections