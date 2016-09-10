/**
 * Balanced Binary Tree
 *
 * cpselvis(cpselvis@gmail.com)
 * September 9th, 2016
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
  bool isBalanced(TreeNode* root) {
    if (root == NULL)
    {
      return true;
    }
    int leftDepth = depth(root -> left);
    int rightDepth = depth(root -> right);

    return abs(leftDepth - rightDepth) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
  }

  int depth(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    return max(depth(root -> left), depth(root -> right)) + 1;
  }
};

int main(int argc, char **argv)
{

}
