all:
	rm -f include/*.o include/*.so
	clang++ -std=c++20 -fPIC -c include/ListNode.cc -o include/ListNode.o
	clang++ -std=c++20 -shared -o include/libListNode.so include/ListNode.o
	clang++ -std=c++20 -fPIC -c include/TreeNode.cc -o include/TreeNode.o
	clang++ -std=c++20 -shared -o include/libTreeNode.so include/TreeNode.o
	clang++ -std=c++20 -fPIC -c include/Node.cc -o include/Node.o
	clang++ -std=c++20 -shared -o include/libNode.so include/Node.o
	clang++ -std=c++20 -fPIC -c include/Utils.cc -o include/Utils.o
	clang++ -std=c++20 -shared -o include/libUtils.so include/Utils.o
	export LD_LIBRARY_PATH=../include:$LD_LIBRARY_PATH

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
