#include "ListNode.h"
#include "TreeNode.h"

namespace q109 {

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return new TreeNode(head->val);

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    prev->next = nullptr;
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
  }
};

}  // namespace q109
