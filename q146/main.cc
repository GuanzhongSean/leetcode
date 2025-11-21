#include "Utils.h"

using namespace std;

class LRUCache {
   public:
	class Node {
	   public:
		int key;
		int val;
		Node* prev;
		Node* next;

		Node(int key, int val) {
			this->key = key;
			this->val = val;
		}
	};

	Node* head = new Node(-1, -1);
	Node* tail = new Node(-1, -1);

	int cap;
	unordered_map<int, Node*> m;

	LRUCache(int capacity) {
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addNode(Node* newnode) {
		Node* temp = head->next;

		newnode->next = temp;
		newnode->prev = head;

		head->next = newnode;
		temp->prev = newnode;
	}

	void deleteNode(Node* delnode) {
		Node* prevv = delnode->prev;
		Node* nextt = delnode->next;

		prevv->next = nextt;
		nextt->prev = prevv;
	}

	int get(int key) {
		if (m.find(key) != m.end()) {
			Node* resNode = m[key];
			int ans = resNode->val;

			deleteNode(resNode);
			addNode(resNode);
			m[key] = head->next;
			return ans;
		}
		return -1;
	}

	void put(int key, int value) {
		if (m.find(key) != m.end()) {
			Node* curr = m[key];
			m.erase(key);
			deleteNode(curr);
			delete curr;
		}

		if (m.size() == cap) {
			Node* lru = tail->prev;
			m.erase(lru->key);
			deleteNode(lru);
			delete lru;
		}

		addNode(new Node(key, value));
		m[key] = head->next;
	}

	~LRUCache() {
		Node* curr = head;
		while (curr != nullptr) {
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
	}
};

int main() {
	LRUCache lRUCache = LRUCache(2);
	lRUCache.put(1, 1);	 // cache is {1=1}
	lRUCache.put(2, 2);	 // cache is {1=1, 2=2}
	EXPECT_EQ(lRUCache.get(1), 1);	 // return 1
	lRUCache.put(3, 3);	 // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	EXPECT_EQ(lRUCache.get(2), -1);	 // returns -1 (not found)
	lRUCache.put(4, 4);	 // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	EXPECT_EQ(lRUCache.get(1), -1);	 // return -1 (not found)
	EXPECT_EQ(lRUCache.get(3), 3);	 // return 3
	EXPECT_EQ(lRUCache.get(4), 4);	 // return 4
	print("All test cases passed!");
	return 0;
}
