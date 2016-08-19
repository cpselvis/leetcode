/**
 * Merge Two Sorted Lists
 * Recursive.
 *
 * cpselvis (cpselvis@gmail.com)
 * August 19, 2016
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p;
    if (l1 == NULL)
    {
      return l2;
    }
    if (l2 == NULL)
    {
      return l1;
    }
    if (l1 -> val < l2 -> val)
    {
      p = l1;
      p -> next = mergeTwoLists(l1 -> next, l2);
    }
    else
    {
      p = l2;
      p -> next = mergeTwoLists(l1, l2 -> next);
    }
    return p;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  ListNode *l1 = new ListNode(1);
  l1 -> next = new ListNode(3);
  l1 -> next -> next = new ListNode(5);
  l1 -> next -> next -> next = new ListNode(7);
  ListNode *l2 = new ListNode(2);
  l2 -> next = new ListNode(4);
  l2 -> next -> next = new ListNode(6);
  l2 -> next -> next -> next = new ListNode(8);
  ListNode *l3 = s.mergeTwoLists(l1, l2);
  while (l3 -> next != NULL)
  {
    cout << l3 -> val << endl;
    l3 = l3 -> next;
  }  
}  
