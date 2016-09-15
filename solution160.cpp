/**
 * Intersection of Two Linked Lists
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *p = headA;
    ListNode *q = headB;

    bool flag1 = true;
    bool flag2 = true;
    
    while (headA != NULL && headB != NULL)
    {
      if (headA == headB)
      {
	return headA;
      }
      headA = headA -> next;
      headB = headB -> next;

      if (headA == NULL && flag1)
      {
	headA = q;
	flag1 = false;
      }
      if (headB == NULL && flag2)
      {
	headB = p;
	flag2 = false;
      }
      cout << "headA:" << headA -> val << endl;
      cout << "headB:" << headB -> val << endl;
    }

    return NULL;
  }
};

int main(int argc, char **argv)
{
  ListNode *headA = new ListNode(1);
  headA -> next = new ListNode(2);
  
  ListNode *insec = new ListNode(3);
  insec -> next = new ListNode(4);
  insec -> next -> next = new ListNode(5);

  ListNode *headB = new ListNode(6);
  headB -> next = new ListNode(7);
  headB -> next -> next = new ListNode(8);

  headA -> next -> next = insec;
  headB -> next -> next -> next = insec;

  Solution s;
  ListNode *intersection = s.getIntersectionNode(headA, headB);
  cout << intersection -> val << endl;
}
