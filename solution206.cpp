/**
 * Reverse Linked List
 *
 * cpselvis(cpselvis@gmail.com)
 * September 8th, 2016
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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head -> next == NULL)
    {
      return head;
    }

    ListNode *prev = NULL;
    while (head != NULL)
    {
      ListNode *next = head -> next;
      head -> next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};


int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(3);
  
  Solution s;
  ListNode *p = s.reverseList(head);

  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
