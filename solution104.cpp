/**
 * Maximum Depth of Binary Tree
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 4th, 2016
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
  int ret = 0;
  int maxDepth(TreeNode* root) {
    dfs(root, 0);
    return ret;
  }

  void dfs(TreeNode * root, int n)
  {
    if (root != NULL)
    {
      n ++;
      ret = n > ret ? n : ret;
      dfs(root -> left, n);
      dfs(root -> right, n);
    }
  }
};


int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(0);
  root -> right = new TreeNode(1);
  root -> left -> left = new TreeNode(0);
  root -> left -> right = new TreeNode(1);
  root -> right -> left = new TreeNode(0);
  root -> right -> right = new TreeNode(1);
  root -> right -> left -> left = new TreeNode(0);

  Solution s;
  cout << s.maxDepth(root) << endl;
}
