# This Makefile builds the C code for a window that shows video feed.
# cflags = -Wimplicit-function-declaration
# The target "all" is the default target. It builds the executable file "main".
all: main
# The target "main" builds the executable file "main" from the source file "main.c".
# gcc -o main main.c -I/opt/homebrew/Cellar/gtk4/4.10.4/include/gtk-4.0/gtk/
main: main.c
	gcc $(shell pkg-config --cflags gtk4) -o main main.c $(pkg-config --libs gtk4)
# The target "clean" removes the executable file "main".
clean:
	rm -rf main
