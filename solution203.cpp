/**
 * Remove Linked List Elements
 *
 * cpselvis(cpselvis@gmail.com)
 * September 9th, 2016
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
  ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL)
    {
      return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;

    ListNode *pre;
    pre = dummy;

    while (head != NULL)
    {
      ListNode *pnext = head -> next;
      if (head -> val == val)
      {
	pre -> next = pnext;
      }
      else
      {
	pre = head;
      }
      head = head -> next;
    }
    
    return dummy -> next;
  }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(6);
  head -> next -> next -> next = new ListNode(3);
  head -> next -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next -> next = new ListNode(5);
  head -> next -> next -> next -> next -> next -> next = new ListNode(6);

  Solution s;
  ListNode *p = s.removeElements(head , 6);

  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
