/**
 * Insertion Sort List
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
  ListNode* insertionSortList(ListNode* head) {
    while (head == NULL || head -> next == NULL)
    {
      return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;

    ListNode *curr = head;
    while (curr -> next != NULL)
    {
      if (curr -> next -> val < curr -> val)
      {
	ListNode *pre = dummy;
	while (pre -> next -> val < curr -> next -> val)
	{
	  pre = pre -> next;
	}
	ListNode *tmp = curr -> next;
	curr -> next = tmp -> next;
	tmp -> next = pre -> next;
	pre -> next = tmp;
      }
      else
      {
	curr = curr -> next;
      }
    }
    return dummy -> next;
  }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(3);
  head -> next -> next = new ListNode(2);
  head -> next -> next -> next = new ListNode(5);
  head -> next -> next -> next -> next = new ListNode(4);

  Solution s;
  ListNode *p = s.insertionSortList(head);
  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
