#include "Utils.h"

namespace q23 {

using namespace std;

namespace V1 {
class Solution {
   public:
	ListNode* mergeKLists(vector<ListNode*> lists) {  // more efficient (Map sort)
		map<int, int> mp;
		for (auto& ln : lists) {
			while (ln) {
				mp[ln->val]++;
				ln = ln->next;
			}
		}
		if (!mp.size()) return nullptr;
		ListNode* ans = nullptr;
		ListNode* cur = ans;
		for (auto& v : mp) {
			for (int i = 0; i < v.second; i++) {
				if (!ans) {
					ans = new ListNode(v.first);
					cur = ans;
					continue;
				}
				cur->next = new ListNode(v.first);
				cur = cur->next;
			}
		}
		return ans;
	}
};
}  // namespace V1

namespace V2 {
class Solution {
   public:
	ListNode* mergeKLists(vector<ListNode*> lists) {  // more efficient (Heap sort)
		priority_queue<int, vector<int>, greater<>> pq{};
		for (auto& ln : lists) {
			while (ln) {
				pq.push(ln->val);
				ln = ln->next;
			}
		}
		ListNode* ans = nullptr;
		ListNode* cur = ans;
		while (pq.size()) {
			int x = pq.top();
			pq.pop();
			if (!ans) {
				ans = new ListNode(x);
				cur = ans;
				continue;
			}
			cur->next = new ListNode(x);
			cur = cur->next;
		}
		return ans;
	}
};
}  // namespace V2

namespace V3 {
class Solution {
   public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {  // saves more memory
		ListNode* result = nullptr;
		for (int i = 0; i < lists.size(); i++) {
			ListNode* cur = lists[i];
			ListNode* prev = nullptr;
			if (!result) {
				result = cur;
				lists[i] = nullptr;
				continue;
			}
			while (cur) {
				lists[i] = cur->next;
				cur->next = nullptr;
				insert(result, prev, cur);
				prev = cur;
				cur = lists[i];
			}
		}
		return result;
	}

   private:
	void insert(ListNode*& result, ListNode* start, ListNode* obj) {
		if (!result) {
			result = obj;
			return;
		}
		if (!start) start = result;
		if (!obj) return;
		ListNode* prev = nullptr;
		while (start) {
			if (start->val > obj->val) {
				if (prev) {
					prev->next = obj;
				} else {
					result = obj;
				}
				obj->next = start;
				break;
			} else {
				if (start->next) {
					prev = start;
					start = start->next;
				} else {
					start->next = obj;
					break;
				}
			}
		}
	}
};
}  // namespace V3

inline namespace V4 {
class Solution {
	struct Compare {
		bool operator()(ListNode* a, ListNode* b) const {
			return a->val > b->val;	 // min-heap
		}
	};

   public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
		for (ListNode* head : lists)
			if (head) pq.push(head);
		ListNode dummy = ListNode(-1);
		ListNode* temp = &dummy;
		while (!pq.empty()) {
			ListNode* top = pq.top();
			temp->next = top;
			temp = top;
			pq.pop();
			if (top->next) pq.push(top->next);
		}
		temp = dummy.next;
		dummy.next = nullptr;
		return temp;
	}
};
}  // namespace V4

}  // namespace q23
