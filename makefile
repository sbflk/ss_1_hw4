CC = gcc
OBJECTS_MAIN = main.o
FLAGS = -Wall -g

all: graph

graph: $(OBJECTS_MAIN) nodes.o edges.o algo.o
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) nodes.o edges.o algo.o

main.o: main.c nodes.h edges.h algo.h
	$(CC) $(FLAGS) -c main.c

nodes.o: nodes.c nodes.h
	$(CC) $(FLAGS) -c nodes.c

edges.o: edges.c edges.h
	$(CC) $(FLAGS) -c edges.c

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c


.PHONY = clean all

clean: 
	rm -f *.o graph