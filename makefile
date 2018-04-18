CC = gcc
CFLAGS = -ansi -DDEBUG -g -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`

reversi: main.o plateau.o jeux.o arbre.o ia.o
	$(CC) main.o plateau.o jeux.o arbre.o ia.o -o reversi $(LDFLAGS) $(LDLIBS)

%o:%c %h
	$(CC) -o $@ -c $< $(OPTIONS)

clean:
	rm -rf *.o reversi
