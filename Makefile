Simulation: simulation.o page.o fcfs.o lfu.o lru.o mfu.o random.o page.h
	gcc $^ -o $@

page.o: page.c
	gcc -c $^ -o $@

simulation.o: simulation.c
	gcc -c $^ -o $@

fcfs.o: fcfs.c
	gcc -c $^ -o $@

lfu.o: lfu.c
	gcc -c $^ -o $@

lru.o: lru.c
	gcc -c $^ -o $@

mfu.o: mfu.c
	gcc -c $^ -o $@

random.o: random.c
	gcc -c $^ -o $@

clean: 
	rm Simulation *.o *.txt
