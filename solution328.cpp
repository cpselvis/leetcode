/**
 * Odd Even Linked List
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
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL)
    {
      return head;
    }

    ListNode *odd = head;
    ListNode *even = head -> next;
    ListNode *evenHead = even;

    while (even != NULL && even -> next != NULL)
    {
      ListNode *nextOdd = odd -> next -> next;
      ListNode *nextEven = even -> next -> next;
      odd -> next = nextOdd;
      even -> next = nextEven;
      odd = nextOdd;
      even = nextEven;
    }

    odd -> next = evenHead;
    
    return head;
  }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(3);
  head -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next = new ListNode(5);
  head -> next -> next -> next -> next -> next = new ListNode(6);
  head -> next -> next -> next -> next -> next -> next = new ListNode(7);
  Solution s;
  ListNode *p = s.oddEvenList(head);

  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
