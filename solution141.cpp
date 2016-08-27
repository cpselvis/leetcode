/**
 * Linked List Cycle
 * Fast and slow pointer.
 *
 * cpselvis(cpselvis@gmail.com)
 * August 27th, 2016.
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
  bool hasCycle(ListNode *head) {

    if (head == NULL || head -> next == NULL)
    {
      return false;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast -> next && fast -> next -> next)
    {
      fast = fast -> next -> next;
      slow = slow -> next;
      if (slow == fast)
      {
	return true;
      }
    }  

    return false;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  //cout << s.hasCycle() << endl;
}  
