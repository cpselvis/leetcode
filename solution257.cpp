/**
 * Binary Tree Paths
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if (root != NULL)
    {
      dfs(root, "", ret);
    }
    return ret;
  }

  void dfs(TreeNode *root, string str, vector<string> &ret)
  {
    if (root == NULL)
    {
      return;
    }
    if (str == "")
    {
      str = to_string(root -> val);
    }
    else
    {
      str = str + "->" + to_string(root -> val);
    }

    if (root -> left == NULL && root -> right == NULL)
    {
      ret.push_back(str);
    }

    dfs(root -> left, str, ret);
    dfs(root -> right, str, ret);
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left -> right = new TreeNode(5);

  Solution s;
  vector<string> ret = s.binaryTreePaths(root);

  for (auto i : ret)
  {
    cout << i << endl;
  }
}
