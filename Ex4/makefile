CC = gcc
FLAGS = -Wall -g

all: graph
graph: main.c graph.c graph.h functions.h
	$(CC) $(FLAGS) main.c graph.c graph.h functions.h -o graph
.PHONY: clean all

clean:
	rm -f graph