/**
 * Remove Duplicates from Sorted List
 * Dummy head;
 *
 * cpselvis(cpselvis@gmail.com)
 * August 24th, 2016
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;
    ListNode *prev = dummy;
    int prevVal;
    
    while (head != NULL)
    {
      ListNode *next = head -> next;

      if (prevVal != head -> val)
      {
	prevVal = head -> val;
        prev = head;
      }
      else
      {
	prev -> next = next;
      }
      head = head -> next;
    }
    return dummy -> next;
  }
};

int main(int argc, char **argv)
{
  ListNode *l1 = new ListNode(-1);
  l1 -> next = new ListNode(0);
  l1 -> next -> next = new ListNode(0);
  l1 -> next -> next -> next = new ListNode(0);
  l1 -> next -> next -> next -> next = new ListNode(3);

  Solution s;
  ListNode *l2 = s.deleteDuplicates(l1);
  while (l2 != NULL)
  {
    cout << l2 -> val << endl;
    l2 = l2 -> next;
  }  
}  
