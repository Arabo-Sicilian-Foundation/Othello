CC = gcc
CFLAGS = -ansi -DDEBUG -g -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`

reversi: modules/main.o modules/plateau.o modules/jeux.o modules/arbre.o modules/ia.o
	$(CC) modules/main.o modules/plateau.o modules/jeux.o modules/arbre.o modules/ia.o -o reversi $(LDFLAGS) $(LDLIBS)

all: modules/main.o modules/plateau.o modules/jeux.o modules/arbre.o modules/ia.o
	$(CC) modules/main.o modules/plateau.o modules/jeux.o modules/arbre.o modules/ia.o -o reversi $(LDFLAGS) $(LDLIBS)
	pdflatex latex/rapport

%o:%c %h
	$(CC) -o $@ -c $< $(OPTIONS)

clean:
	rm -rf modules/*.o reversi latex/rapport.* rapport.aux rapport.log rapport.toc
