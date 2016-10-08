/**
 * System design: Binary Search Tree Iterator
 *
 * cpselvis(cpselvis@gamil.com)
 * Oct 8th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;
/**
 * Definition for binary tree
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
  stack<TreeNode *> st;
public:
  BSTIterator(TreeNode *root) {
    while (root != NULL)
    {
      st.push(root);
      root = root -> left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !st.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *node = st.top();
    st.pop();
    int ret = node -> val;
    if (node -> right != NULL)
    {
      node = node -> right;
      while (node != NULL)
      {
	st.push(node);
	node = node -> left;
      }
    }
    return ret;
  }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(5);
  root -> left = new TreeNode(3);
  root -> right = new TreeNode(7);
  root -> left -> left = new TreeNode(2);
  root -> left -> right = new TreeNode(4);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(8);
  BSTIterator *bstIt = new BSTIterator(root);
  while(bstIt -> hasNext())
  {
    cout << bstIt -> next() << endl;
  }
}
