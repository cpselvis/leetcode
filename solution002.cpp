/**
 * @file Leetcode: Add Two Numbers.
 * 
 * @author cpselvis (cpselvis@gmail.com)
 * @date   2016.7.5
 */
#include<cstdio>

/*Definition for singly-linked list.*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
      {
	return l2;
      }
    if (l2 == NULL)
      {
	return l1;
      }
    ListNode *p, *l3;
    p = new ListNode(-1);
    int carry = 0;
    l3 = p;

    while (l1 != NULL || l2 != NULL)
      {
	if (l1 != NULL)
	  {
	    carry += l1 -> val;
	    l1 = l1 -> next;
	  }
	if (l2 != NULL)
	  {
	    carry += l2 -> val;
	    l2 = l2 -> next;
	  }
	l3 -> next = new ListNode(carry % 10);
	l3 = l3 -> next;
	carry = carry / 10;
      }

    if (carry == 1)
      {
	l3 -> next = new ListNode(1);
      }
    return p -> next;
  }
};

int main(int argc, char **argv)
{
  ///////  Test case.
  ///////  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  ///////  Output: 7 -> 0 -> 8
  Solution s;
  ListNode *l1, *l2, *l3;
  l1 = new ListNode(5);
  l2 = new ListNode(5);
  l3 = s.addTwoNumbers(l1, l2);
  printf("%d\n", l3 -> val);
}
