/**
 * Remove Nth Node From End of List
 * Double pointer.
 *
 * cpselvis(cpselvis@gmail.com)
 * August 18th, 2016
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    while (n --)
    {
      fast = fast -> next;
    }

    while (fast == NULL)
    {
      return head -> next;
    }  

    while (fast -> next != NULL)
    {
      fast = fast -> next;
      slow = slow -> next;
    }

    slow -> next = slow -> next -> next;
    return head;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  ListNode *p = new ListNode(1);
  // p -> next = new ListNode(2);
  // p -> next -> next = new ListNode(3);
  ListNode *ret = s.removeNthFromEnd(p, 1);
  cout << ret -> val << endl;
}  
