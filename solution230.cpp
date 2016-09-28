/**
 * Kth Smallest Element in a BST
 *
 * cpselvis(cpselvis@gmail.com)
 * September 28th, 2016
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
  int kthSmallest(TreeNode* root, int k) {
    if (root == NULL) return 0;
    stack<TreeNode *> st;
    TreeNode *pnode = root;
    int count = 0;
    
    while (pnode != NULL || !st.empty())
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
	count ++;
	if (count == k)
	{
	  return pnode -> val;
	}
	pnode = pnode -> right;
      }
    }
    return 0;
  }
};


int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(5);
  root -> left = new TreeNode(3);
  root -> right = new TreeNode(7);
  root -> left -> left = new TreeNode(1);
  root -> left -> right = new TreeNode(4);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(8);
  Solution s;
  cout << s.kthSmallest(root, 1) << endl;
}
