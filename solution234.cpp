/**
 * Palindrome Linked List
 *
 * cpselvis(cpselvis@gmail.com)
 * September 28th, 2016
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
  bool isPalindrome(ListNode* head) {
    if (head == NULL || head -> next == NULL)
    {
      return true;
    }

    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast -> next != NULL)
    {
      fast = fast -> next -> next;
      slow = slow -> next;
    }

    // Reverse partion list from middle to end of list.
    ListNode *newHead = reverseList(slow);
    while (newHead != NULL)
    {
      if (head -> val != newHead -> val)
      {
	return false;
      }
      newHead = newHead -> next;
      head = head -> next;
    }
    return true;
  }
  ListNode *reverseList(ListNode *node)
  {
    ListNode *newHead = NULL;
    while (node != NULL)
    {
      ListNode *next = node -> next;
      node -> next = newHead;
      newHead = node;
      node = next;
    }
    return newHead;
  }
};


int main(int argc, char **argv)
{
  ListNode *head = new ListNode(0);
  head -> next = new ListNode(0);
  Solution s;
  cout << s.isPalindrome(head) << endl;
}
