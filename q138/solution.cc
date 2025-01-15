#include <unordered_map>

#include "Node.h"

namespace q138 {

using Node = Random::Node;

class Solution {
   public:
	Node* copyRandomList(Node* head) {
		if (!head) return nullptr;

		std::unordered_map<Node*, Node*> old_to_new;

		Node* curr = head;
		while (curr) {
			old_to_new[curr] = new Node(curr->val);
			curr = curr->next;
		}

		curr = head;
		while (curr) {
			old_to_new[curr]->next = old_to_new[curr->next];
			old_to_new[curr]->random = old_to_new[curr->random];
			curr = curr->next;
		}

		return old_to_new[head];
	}
};

}  // namespace q138
