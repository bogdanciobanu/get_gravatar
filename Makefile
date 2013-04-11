.PHONY: all
all: build

build: main.o get_gravatar.o
	gcc  get_gravatar.o main.o  -o get_gravatar `pkg-config --cflags --libs libsoup-2.4 glib-2.0 `

main.o: main.c
	gcc -c  main.c `pkg-config --cflags --libs libsoup-2.4 glib-2.0 ` 

get_gravatar.o: get_gravatar.c
	gcc -c  get_gravatar.c `pkg-config --cflags --libs libsoup-2.4 glib-2.0 `

clean:
	rm -rf *.o exec
