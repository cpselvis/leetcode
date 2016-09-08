/**
 * Binary Tree Inorder Traversal
 *
 * cpselvis(cpselvis@gmail.com)
 * September 9th, 2016
 */
#include<iostream>
#include<vector>
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;

    if (root == NULL)
    {
      return ret;
    }

    stack<TreeNode *> st;
    TreeNode *pnode = root;

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
	ret.push_back(pnode -> val);
	pnode = pnode -> right;
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> right = new TreeNode(2);
  root -> right -> left = new TreeNode(3);

  Solution s;
  vector<int> vec = s.inorderTraversal(root);
  for (auto i : vec)
  {
    cout << i << endl;
  }
}
