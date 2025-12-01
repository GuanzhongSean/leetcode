#include "solution.cc"

using std::vector;

int main() {
	q23::Solution s;
	vector<ListNode*> lists{
		nullptr,
		new ListNode{1},
		new ListNode{1},
		new ListNode{-4},
		new ListNode{1, new ListNode{4, new ListNode{5}}},
		new ListNode{1, new ListNode{3, new ListNode{4}}},
		new ListNode{2, new ListNode{6}},
	};
	auto result = s.mergeKLists(lists);
	if (result) result->print();
	delete result;
}
