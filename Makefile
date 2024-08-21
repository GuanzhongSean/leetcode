all:
	clang-format --style=Google --dump-config > .clang-format
	clang++ -std=c++20 -fPIC -c include/ListNode.cc -o include/ListNode.o
	clang++ -std=c++20 -shared -o include/ListNode.so include/ListNode.o
	clang++ -std=c++20 -fPIC -c include/utils.cc -o include/utils.o
	clang++ -std=c++20 -shared -o include/utils.so include/utils.o

clean:
	rm */a.out

fmt:
	clang-format -i --verbose **/*.cc
	clang-format -i --verbose **/*.h
	yapf -i --verbose **/*.py
	npx prettier --write **/*.js
