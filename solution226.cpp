/**
 * Invert Binary Tree
 *
 * cpselvis(cpselvis@gmail.com)
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
  TreeNode* invertTree(TreeNode* root) {
    dfs(root);
    return root;
  }

  void dfs(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    swap(root -> left, root -> right);
    dfs(root -> left);
    dfs(root -> right);
  }  
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(4);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(7);
  root -> left -> left = new TreeNode(1);
  root -> left -> right = new TreeNode(3);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(9);

  Solution s;
  TreeNode *node = s.invertTree(root);
  cout << node -> val << endl;
  cout << node -> left -> val << endl;
  cout << node -> right -> val << endl;
  cout << node -> left-> left -> val << endl;
  cout << node -> left -> right -> val << endl;
  cout << node -> right -> left -> val << endl;
  cout << node -> right -> right -> val << endl;
}
