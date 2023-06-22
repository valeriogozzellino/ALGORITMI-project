CC = gcc
all: bin/main_ex2 bin/SkipList_tests
tests: bin/SkipList_tests

CFLAGS = -g 

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS) 
	$(CC) $(CFLAGS) -c $< -o $@

bin/main_ex2: build/compare.o build/SkipList.o build/main_ex2.o $(COMMON_DEPS)
	$(CC) -o bin/main_ex2 build/main_ex2.o build/SkipList.o build/compare.o

bin/SkipList_tests: build/SkipList_tests.o build/SkipList.o build/compare.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/SkipList_tests build/SkipList_tests.o build/SkipList.o build/compare.o build/unity.o

clean: 
	rm -f build/* bin/*