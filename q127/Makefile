CXX = clang++
CXXFLAGS = -std=c++20 -I../include -I../
LDFLAGS = -L../include -lListNode -lTreeNode -lNode -lUtils -lgtest -lgtest_main -pthread

all: clean exec

exec: main.o
	$(CXX) $(CXXFLAGS) -o exec main.o $(LDFLAGS)
	./exec

python:
	python solution.py

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

clean:
	rm -f *.o exec

.PHONY: all clean exec
