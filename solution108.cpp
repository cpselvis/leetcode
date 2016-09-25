/**
 * Convert Sorted Array to Binary Search Tree
 *
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
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
   TreeNode* sortedArrayToBST(vector<int>& nums) {
     return dfs(nums, 0, nums.size());
   }
   TreeNode* dfs(vector<int> &nums, int left, int right)
   {
     if (left > right)
     {
       return NULL;
     }
     int mid = (left + right) >> 1;

     TreeNode *node = new TreeNode(nums[mid]);

     node -> left = dfs(nums, left, mid - 1);
     node -> right = dfs(nums, mid + 1, right);
     return node;
   }
 };

int main(int argc, char **argv)
{
  Solution s;
  vector<int> vec({1, 2, 4, 5, 6 ,7 , 8});
  s.sortedArrayToBST(vec);
}
