/**
 * Path Sum
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
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL)
    {
      return false;
    }
    vector<int> nums;
    dfs(root, nums, 0);
    for (auto i : nums)
    {
      if (sum == i)
      {
        return true;
      }
    }
    return false;
  }
  void dfs(TreeNode *root, vector<int> &nums, int num)
  {
    num = num + root -> val;
    if (root -> left != NULL)
    {
      dfs(root -> left, nums, num);
    }
    if (root -> right != NULL)
    {
      dfs(root -> right, nums, num);
    }
    if (root -> left == NULL && root -> right == NULL)
    {
      nums.push_back(num);
    }
  }
};

int main(int argc, char **argv)
{
  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(2);

  Solution s;
  cout << s.hasPathSum(root, 3) << endl;
}
