CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Wextra -Werror
TEST_LIBS=-lgtest_main -lgtest -lpthread

.PHONY: test clean

all: main test_bin

main: allocator.o main.cpp
	$(CC) $(FLAGS) main.cpp -o main
	./main

allocator.o: allocator.cpp allocator.hpp
	$(CC) $(FLAGS) allocator.cpp -c

test_bin: allocator.o test.cpp
	$(CC) $(FLAGS) allocator.o test.cpp -o test_bin $(TEST_LIBS)

test:
	./test_bin

clean:
	rm -f *.o main test_bin
