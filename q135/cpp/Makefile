CXX = clang++
CXXFLAGS = -std=c++20 -I../../include -I../../
LDFLAGS = -L../../include -lListNode -lTreeNode -lNode -lGraph -lUtils -lgtest -lgtest_main -pthread

all: clean exec

exec: main.o
	$(CXX) $(CXXFLAGS) -o exec main.o $(LDFLAGS)
	LD_LIBRARY_PATH=../../include ./exec

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

clean:
	rm -f *.o exec
