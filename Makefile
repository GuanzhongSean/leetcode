all: ListNode TreeNode Node Graph Utils
	sudo cp include/*.so /usr/local/lib/
	sudo ldconfig

python_bindings:
	cd include/python_bindings && python3 setup.py build_ext --inplace

ListNode:
	rm -f include/ListNode.o include/libListNode.so
	clang++ -std=c++20 -fPIC -c include/ListNode.cc -o include/ListNode.o
	clang++ -std=c++20 -shared -o include/libListNode.so include/ListNode.o

TreeNode:
	rm -f include/TreeNode.o include/libTreeNode.so
	clang++ -std=c++20 -fPIC -c include/TreeNode.cc -o include/TreeNode.o
	clang++ -std=c++20 -shared -o include/libTreeNode.so include/TreeNode.o

Node:
	rm -f include/Node.o include/libNode.so
	clang++ -std=c++20 -fPIC -c include/Node.cc -o include/Node.o
	clang++ -std=c++20 -shared -o include/libNode.so include/Node.o

Graph:
	rm -f include/Graph.o include/libGraph.so
	clang++ -std=c++20 -fPIC -c include/Graph.cc -o include/Graph.o
	clang++ -std=c++20 -shared -o include/libGraph.so include/Graph.o

Utils:
	rm -f include/Utils.o include/libUtils.so
	clang++ -std=c++20 -fPIC -c include/Utils.cc -o include/Utils.o
	clang++ -std=c++20 -shared -o include/libUtils.so include/Utils.o

Utils-opt:
	rm -f include/Utils.o include/libUtils.so
	clang++ -std=c++20 -fPIC -D_LEETCODE_OPTIMIZE_ -c include/Utils.cc -o include/Utils.o
	clang++ -std=c++20 -shared -o include/libUtils.so include/Utils.o

clean:
	rm -f */a.out */exec */*.o */*.so */*.class */src/*.class

fmt:
	clang-format -i --verbose **/*.cc
	clang-format -i --verbose **/*.h
	yapf -i --verbose **/*.py
	npx prettier --write **/*.js

init_fmt:
	clang-format --style=Google --dump-config > .clang-format

init:
	sudo apt install clang clang-format clang-tidy clang-tools
	pip install --upgrade yapf
	npm install --global prettier

.PHONY: clean fmt init_fmt init ListNode TreeNode Node Graph Utils
