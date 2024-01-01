 all:
	gcc main.c ssprintf_ref.c sscanf.c -lm

 run:
	gcc main.c $(ARGS)
	./a.out

 flags:
	gcc -Wall main.c ssprintf_ref.c sscanf.c -lm	