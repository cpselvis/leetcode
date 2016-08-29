/**
 * Linked List Cycle II
 * This question is based on math theroy describe as flollows:
 * Suppose circumference is r, the whole linked list length is l, from  beginning to cycle node is a and cycle node to encounter node is x, when fast and slow node meet, fast has run 2s, slow is s, then we have expression:
 *   2s = s + n * r
 *      => s = n * r
 *   a + x = n * r
 *   r = l - a
 *     => a + x = (n - 1) * r + r
 *     => a = (n - 1) * r + r - x
 *     => a = (n - 1) * r + l - a - x
 * Due to analysis, we have conclusion: if two pointer is from head and encounter and if they run by same speed, they will meet at cycle point.
 *
 * cpselvis (cpselvis@gmail.com)
 * August 29th, 2016
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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    bool hasCycle = false;

    if (head == NULL || head -> next == NULL)
    {
      return NULL;
    }
    
    while (fast && fast -> next)
    {
      fast = fast -> next -> next;
      slow = slow -> next;

      if (fast == slow)
      {
	hasCycle = true;
	break;
      }	
    }

    if (!hasCycle)
    {
      return NULL;
    }

    slow = head;
    while (slow != fast)
    {
      slow = slow -> next;
      fast = fast -> next;
    }
    
    return slow;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  //cout << s.detectCycle();
}  
