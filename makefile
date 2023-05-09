bubblesort:
	gcc bubblesort.c -c -o bubblesort.o -g

insertionsort:
	gcc insertionsort.c -c -o insertionsort.o -g

directselectionsort:
	gcc directselectionsort.c -c -o directselectionsort.o -g

shellsort:
	gcc shellsort.c -c -o shellsort.o -g

quicksort:
	gcc quicksort.c -c -o quicksort.o -g

heapsort:
	gcc heapsort.c -c -o heapsort.o -g -std=c99

sort: bubblesort insertionsort directselectionsort shellsort quicksort heapsort
	ld -r \
	bubblesort.o insertionsort.o \
	directselectionsort.o shellsort.o \
	quicksort.o heapsort.o \
	-o sort.o
	rm -f bubblesort.o insertionsort.o directselectionsort.o shellsort.o quicksort.o heapsort.o

utils: utils.c
	gcc utils.c -c -o utils.o -std=c99

all: sort utils
	gcc sort.o utils.o main.c -o main -std=c99
	rm sort.o utils.o
	./main

clean:
	rm -f *.o main