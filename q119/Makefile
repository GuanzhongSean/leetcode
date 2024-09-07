all: exec

init:
	cd .. && make -s

build: init exec

exec:
	clang++ -std=c++20 main.cc -L../include -lListNode -lTreeNode -lNode -lutils -I../include -I../
	./a.out

clean:
	rm -f a.out
