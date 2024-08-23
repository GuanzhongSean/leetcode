all: exec

init:
	cd .. && make -s

build: init exec

exec:
	clang++ -std=c++20 solution.cc -L../include -lListNode -lutils -I../include -I../
	./a.out

clean:
	rm -f a.out
