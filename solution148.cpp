/**
 * Sort List
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 16th, 2016
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
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head -> next == NULL)
      return head;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *pre = NULL;
    while (fast && fast -> next)
    {
      pre = slow;
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    pre -> next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return merge(l1, l2);
  }

  ListNode *merge(ListNode *head1, ListNode *head2)
  {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    ListNode *dummy = new ListNode(-1);
    ListNode *newHead = dummy;
    while (head1 != NULL && head2 != NULL)
    {
      if (head1 -> val < head2 -> val)
      {
	newHead -> next = head1;
	head1 = head1 -> next;
      }
      else
      {
	newHead -> next = head2;
	head2 = head2 -> next;
      }
      newHead = newHead -> next;
    }
    if (head1 != NULL)
    {
      newHead -> next = head1;
    }
    else if (head2 != NULL)
    {
      newHead -> next = head2;
    }
    return dummy -> next;
  }
};


int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(3);
  head -> next -> next = new ListNode(5);
  head -> next -> next -> next = new ListNode(2);
  head -> next -> next -> next -> next = new ListNode(4);
  head -> next -> next -> next -> next -> next = new ListNode(6);


  Solution s;
  ListNode *newHead = s.sortList(head);

  while (newHead != NULL)
  {
    cout << newHead -> val << endl;
    newHead = newHead -> next;
  }
}
