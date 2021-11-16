taller5: obj/taller5_good.o
	gcc $^ -o bin/taller5

obj/taller5_good.o: src/taller5_good.c
	gcc -Wall -I include/ -c $^ -o $@

.PHONY: clean

clean:
	rm bin/* obj/*
