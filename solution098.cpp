/**
 * Validate Binary Search Tree
 *
 * cpselvis(cpselvis@gmail.com)
 * September 29th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode *> st;
    TreeNode *pnode = root;

    TreeNode *pre;
    while(!st.empty() || pnode != NULL)
    {
      if (pnode != NULL)
      {
	st.push(pnode);
	pnode = pnode -> left;
      }
      else
      {
	pnode = st.top();
	st.pop();
	if (pre != NULL && pnode -> val <= pre -> val)
	{
	  return false;
	}
	else
	{
	  pre = pnode;
	}
	pnode = pnode -> right;
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);

  Solution s;
  cout << s.isValidBST(root) << endl;
}
