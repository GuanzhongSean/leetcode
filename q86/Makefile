all: init exec

init:
	cd .. && make -s

build:
	clang++ -std=c++20 solution.cc -L../include -lListNode -lutils -I../include -I../

exec: build
	valgrind ./a.out

clean:
	rm -f a.out
