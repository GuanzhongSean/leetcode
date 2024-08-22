all:
	clang-format --style=Google --dump-config > .clang-format
	rm -f include/*.o include/*.so
	clang++ -std=c++20 -fPIC -c include/ListNode.cc -o include/ListNode.o
	clang++ -std=c++20 -shared -o include/libListNode.so include/ListNode.o
	clang++ -std=c++20 -fPIC -c include/utils.cc -o include/utils.o
	clang++ -std=c++20 -shared -o include/libutils.so include/utils.o
	export LD_LIBRARY_PATH=../include:$LD_LIBRARY_PATH

clean:
	rm */a.out

fmt:
	clang-format -i --verbose **/*.cc
	clang-format -i --verbose **/*.h
	yapf -i --verbose **/*.py
	npx prettier --write **/*.js
