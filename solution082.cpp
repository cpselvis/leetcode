/**
 * Remove Duplicates from Sorted List II
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 9th, 2016
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
    if (head == NULL || head -> next == NULL) return head;
    
    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;
    head = dummy;

    while (head -> next != NULL && head -> next -> next != NULL)
    {
      if (head -> next -> val == head -> next -> next -> val)
      {
	int val = head -> next -> val;
	while (head -> next != NULL && head -> next -> val == val)
	{
	  head -> next = head -> next -> next;
	}
      }
      else
      {
	head = head -> next;
      }
    }
    return dummy -> next;
  }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(2);
  head -> next -> next = new ListNode(3);
  head -> next -> next -> next = new ListNode(3);
  head -> next -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next -> next -> next = new ListNode(5);

  Solution s;
  ListNode *node = s.deleteDuplicates(head);
  while(node != NULL)
  {
    cout << node -> val << endl;
    node = node -> next;
  }
}
