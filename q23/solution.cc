#include <functional>
#include <map>
#include <queue>
#include <vector>

#include "ListNode.h"

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

  ListNode* mergeKLists1(
      vector<ListNode*> lists) {  // more efficient (Heap sort)
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

  ListNode* mergeKLists2(vector<ListNode*>& lists) {  // saves more memory
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

int main() {
  Solution s;
  vector<ListNode*> lists{
      nullptr,
      new ListNode{1},
      new ListNode{1},
      new ListNode{-4},
      new ListNode{1, new ListNode{4, new ListNode{5}}},
      new ListNode{1, new ListNode{3, new ListNode{4}}},
      new ListNode{2, new ListNode{6}},
  };
  auto result = s.mergeKLists1(lists);
  if (result) result->print();
  delete result;
  for (auto l : lists) delete l;
}
