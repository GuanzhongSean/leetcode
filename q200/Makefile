CXX = clang++
CXXFLAGS = -std=c++20 -I../include -I../
LDFLAGS = -L../include -lListNode -lTreeNode -lNode -lUtils -lgtest -lgtest_main -pthread

all: exec

exec: main.o
	$(CXX) $(CXXFLAGS) -o exec main.o $(LDFLAGS)
	./exec

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

clean:
	rm -f *.o exec

.PHONY: all clean exec
