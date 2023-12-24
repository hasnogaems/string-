 all:
	gcc main.c ssprintf_ref.c -lm

 run:
	gcc main.c $(ARGS)
	./a.out