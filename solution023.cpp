/**
 * Merge k Sorted Lists
 * Priority queue.
 *
 * cpselvis(cpselvis@gmail.com)
 * August 21th, 2016
 */
#include<iostream>
#include<queue>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Priority queue sort rules.
struct cmp {
  bool operator() (ListNode *a, ListNode *b)
  {
    return a -> val > b -> val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode *, vector<ListNode*>, cmp> pq;

    for (int i = 0; i < lists.size(); i ++)
    {
      if (lists[i] != NULL)
      {
	pq.push(lists[i]);
      }	
    }

    ListNode *head = new ListNode(-1);
    ListNode *p, *tmp;
    p = head;
    while (!pq.empty())
    {
      tmp = pq.top();
      p -> next = tmp;
      p = p -> next;
      pq.pop();

      if (tmp -> next != NULL)
      {
	pq.push(tmp -> next);
      }	
    }
    return head -> next;
  }
};


int main(int argc, char **argv)
{
  ListNode *l1 = new ListNode(1);
  l1 -> next = new ListNode(3);
  l1 -> next -> next = new ListNode(5);

  ListNode *l2 = new ListNode(2);
  l2 -> next = new ListNode(4);
  l2 -> next -> next = new ListNode(6);

  ListNode *l3 = new ListNode(7);
  l3 -> next = new ListNode(9);
  l3 -> next ->next = new ListNode(10);

  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  Solution s;
  ListNode *p = s.mergeKLists(lists);
  while (p != NULL)
  {
    cout << p -> val << endl;
    p = p -> next;
  }  
}  
