/**
 * Partition List
 *
 * cpselvis(cpselvis@gmail.com)
 * September 15th, 2016
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
    ListNode* partition(ListNode* head, int x) {
      ListNode *smallHead = new ListNode(-1);
      ListNode *biggerHead = new ListNode(-1);

      ListNode *smallTail = smallHead;
      ListNode *biggerTail = biggerHead;

      while (head != NULL)
      {
	if (head -> val < x)
	{
	  smallTail -> next = head;
	  head = head -> next;
	  smallTail = smallTail -> next;
	  smallTail -> next = NULL;
	}
	else
	{
	  biggerTail -> next = head;
	  head = head -> next;
	  biggerTail = biggerTail -> next;
	  biggerTail -> next = NULL;
	}
      }
      smallTail -> next = biggerHead -> next;
      return smallHead -> next;
    }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(4);
  head -> next -> next = new ListNode(3);
  head -> next -> next -> next = new ListNode(2);
  head -> next -> next -> next -> next = new ListNode(5);
  head -> next -> next -> next -> next -> next = new ListNode(2);

  Solution s;
  ListNode *p = s.partition(head, 3);
  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }
}
