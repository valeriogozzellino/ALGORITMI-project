CC = gcc
all: bin/merge_binary_insertion_sort bin/merge_binary_insertion_sort_test
tests: bin/merge_binary_insertion_sort_test

CFLAGS = -g #inserisce opzioni di debug nel codice 

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS) 
	$(CC) $(CFLAGS) -c $< -o $@

bin/merge_binary_insertion_sort: build/main_ex1.o build/merge_binary_insertion_sort.o build/compare.o build/record_managment.o  $(COMMON_DEPS)
	$(CC) -o bin/main_ex1 build/main_ex1.o build/merge_binary_insertion_sort.o build/compare.o build/record_managment.o 

bin/merge_binary_insertion_sort_test: build/merge_binary_insertion_sort_test.o build/merge_binary_insertion_sort.o build/compare.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/merge_binary_insertion_sort_test build/merge_binary_insertion_sort_test.o build/merge_binary_insertion_sort.o build/compare.o build/unity.o

clean: 
	rm -f build/* bin/*

		