/**
 * Binary Tree Zigzag Level Order Traversal
 *
 * Nov 8th, 2016
 */
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode *> q;
    vector<vector<int> > ret;
    if (root == NULL) return ret;
    q.push(root);

    int i = 0;
    while (!q.empty())
    {
      queue<TreeNode *> tmpQueue;
      vector<int> tmpVec;

      while (!q.empty())
      {
        TreeNode *node = q.front();
	q.pop();
	if (node -> left)
	{
	  tmpQueue.push(node -> left);
	}
	if (node -> right)
	{
	  tmpQueue.push(node -> right);
	}
	tmpVec.push_back(node -> val);
      }
      q = tmpQueue;
      if (i % 2 != 0)
      {
        reverse(tmpVec.begin(), tmpVec.end());
      }
      i ++;
      ret.push_back(tmpVec);
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;

  TreeNode *root = new TreeNode(3);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(20);
  root -> right -> left = new TreeNode(15);
  root -> right -> right = new TreeNode(7);

  vector<vector<int> > ret = s.zigzagLevelOrder(root);
  for (auto i : ret)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
