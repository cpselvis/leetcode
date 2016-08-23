/**
 * Swap Nodes in Pairs
 * Dummy head.
 * cpselvis (cpselvis@gmail.com)
 * August 22th, 2016
 */
#include<iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;
    ListNode *prev = dummy;

    while (head && head -> next)
    {
      ListNode *next = head -> next -> next;
      prev -> next = head -> next;
      prev -> next -> next = head;
      head -> next = next;
      prev = head;
      head = next;
    }
    return dummy -> next;
  }
};

int main(int argc, char **argv)
{
  ListNode *l1 = new ListNode(1);
  l1 -> next = new ListNode(2);
  l1 -> next -> next = new ListNode(3);
  l1 -> next -> next -> next = new ListNode(4);

  Solution s;
  ListNode *l2 = s.swapPairs(l1);
  while (l2 != NULL)
  {
    cout << l2 -> val << endl;
    l2 = l2 -> next;
  }  
}  
