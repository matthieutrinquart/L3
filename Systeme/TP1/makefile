CC=gcc
CFLAGS=-Wall

#-no-pie

.c:
	$(CC) $(CFLAGS) -o $@  $<
.o:
	$(CC) $(CFLAGS) -o $@  $<

.c.o:
	$(CC) $(CFLAGS) -c $<

.h.c:
	touch $@

mm: mm.o main.o
	$(CC) $(CFLAGS) -o mm main.o mm.o

mmgui : mmgui.c mm.o mm.h
	$(CC) $(CFLAGS) -g mmgui.c mm.o -o mmgui `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
	./mmgui

all :  mm mmgui

clean:
	rm *.o mm mmgui

helloworld : helloworld.c
	gcc -Wall -g helloworld.c -o helloworld `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
	helloworld
