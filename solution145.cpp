/**
 * Binary Tree Postorder Traversal
 *
 * cpselvis (cpselvis@gmail.com)
 * August 28th, 2016
 */

#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    dfs(ret, root);
    return ret;
  }
  void dfs(vector<int> &ret, TreeNode *root)
  {
    if (root != NULL)
    {
      dfs(ret, root -> left);
      dfs(ret, root -> right);
      ret.push_back(root -> val);
    }
  }
};


int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> right = new TreeNode(2);
  root -> right -> left = new TreeNode(3);

  Solution s;
  vector<int> ret = s.postorderTraversal(root);

  for (auto i : ret)
  {
    cout << i << endl;
  }
}  
