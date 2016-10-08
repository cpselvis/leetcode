/**
 * Delete Node in a Linked List
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 8th, 2016
 */


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    if (node != NULL)
      {
	node -> val = node -> next -> val;
	node -> next = node -> next -> next;
      }
  }
};
