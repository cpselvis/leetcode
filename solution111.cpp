1/**
 * Minimum Depth of Binary Tree
 *
 * cpselvis (cpselvis@gmail.com)
 * September 10th, 2016
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
  int minDepth(TreeNode* root) {
    if (root == NULL)
    {
      return 0;
    }
    int lDepth = minDepth(root -> left);
    int rDepth = minDepth(root -> right);
    return 1 + (min(lDepth, rDepth) ? min(lDepth, rDepth) : max(lDepth, rDepth));
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root ->left = new TreeNode(1);
  root -> right = new TreeNode(1);
  root -> left -> left = new TreeNode(1);

  Solution s;
  cout << s.minDepth(root) << endl;
}
