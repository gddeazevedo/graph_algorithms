all: */*.h */*.c main.c
	cc */*.h */*.c main.c -o run.out