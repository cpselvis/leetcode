/**
 * Symmetric Tree
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 3th, 2016
 */
#include<iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
    {
      return true;
    }
    return isMirror(root -> left, root -> right);
  }

  bool isMirror(TreeNode *t1, TreeNode *t2)
  {
    if (t1 == NULL && t2 == NULL)
    {
      return true;
    }
    if (t1 == NULL || t2 == NULL)
    {
      return false;
    }
    return t1 -> val == t2 -> val && isMirror(t1 -> left, t2 -> right) && isMirror(t1 -> right, t2 -> left);
  }
};


int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(1);
  root -> right = new TreeNode(1);
  root -> left -> left = new TreeNode(1);
  root -> left -> right = new TreeNode(0);
  root -> right -> left = new TreeNode(0);
  root -> right -> right = new TreeNode(1);

  Solution s;
  cout << s.isSymmetric(root) << endl;
}
