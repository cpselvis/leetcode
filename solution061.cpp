/**
 * Rotate List
 *
 * cpselvis(cpselvis@gmail.com)
 * September 7th, 2016
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || k == 0)
    {
      return head;
    }
    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;
    ListNode *fast = head, *slow = head;
    int listCount = countListLength(head);

    k %= listCount;

    while (k --)
    {
      fast = fast -> next;
    }

    while (fast -> next)
    {
      fast = fast -> next;
      slow = slow -> next;
    }

    if (slow -> next == NULL)
    {
      return head;
    }
    dummy -> next = slow -> next;
    fast -> next = head;
    slow -> next = NULL;
    return dummy -> next;
  }
  int countListLength(ListNode *head)
  {
    int count = 0;
    while (head != NULL)
    {
      head = head -> next;
      count ++;
    }
    return count;
  }
};

int main(int argc, char **argv)
{
  ListNode *head = new ListNode(1);
  head -> next = new ListNode(2);
  //  head -> next -> next = new ListNode(3);
  //head -> next -> next -> next = new ListNode(4);
  //head -> next -> next -> next -> next = new ListNode(5);

  Solution s;
  ListNode *ret = s.rotateRight(head, 2);

  while (ret != NULL)
  {
    cout << ret -> val << endl;
    ret = ret -> next;
  }
}
