 all:
	gcc main.c ssprintf_ref.c sscanf.c -lm

 run:
	gcc main.c $(ARGS)
	./a.out