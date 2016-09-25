/**
 * Flatten Binary Tree to Linked List
 * Recursive version.
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
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
  void flatten(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
      TreeNode *pnode = st.top();
      st.pop();

      if (pnode -> right != NULL)
      {
	st.push(pnode -> right);
      }

      if (pnode -> left != NULL)
      {
	st.push(pnode -> left);
      }

      pnode -> left = NULL;
      if (!st.empty())
      {
	pnode -> right = st.top();
      }
    }
    
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(5);
  root -> left -> left = new TreeNode(3);
  root -> left -> right = new TreeNode(4);
  root -> right -> right = new TreeNode(6);

  Solution s;
  s.flatten(root);
}
