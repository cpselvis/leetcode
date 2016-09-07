/**
 * Sum Root to Leaf Numbers
 *
 * cpselvis(cpselvis@gmail.com)
 * September 7th, 2016
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
  int sumNumbers(TreeNode* root) {
    vector<int> nums;
    int ret = 0;
    dfs(root, nums, 0);
    for (auto i : nums)
    {
      ret += i;
    }
    return ret;
  }
  void dfs(TreeNode *root, vector<int> &nums, int num)
  {
    if (root != NULL)
    {
      num = num * 10 + root -> val;
      if (root -> left != NULL)
      {
	dfs(root -> left, nums, num);
      }
      if (root -> right != NULL)
      {
	dfs(root -> right, nums, num);
      }
    }
    if (root == NULL || (root -> left == NULL && root -> right == NULL))
    {
      nums.push_back(num);
    }
  }
};

int main(int argc, char **argv)
{
  TreeNode *root;
  //  TreeNode *root = new TreeNode(1);
  //  root -> left = new TreeNode(0);
  //  root -> right = new TreeNode(3);

  Solution s;
  cout << s.sumNumbers(root) << endl;
}
