/**
 * Construct Binary Tree from Inorder and Postorder Traversal
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }

  TreeNode* dfs(vector<int> &inorder, vector<int> &postorder, int istart, int iend, int pstart, int pend)
  {
    if (istart > iend)
    {
      return NULL;
    }
    TreeNode *root = new TreeNode(postorder[pend]);

    int i;
    for (i = istart; i < iend; i ++)
    {
      if (postorder[pend] == inorder[i])
      {
	break;
      }
    }
    root -> left = dfs(inorder, postorder, istart, i - 1, pstart, pstart + i - istart - 1);
    root -> right = dfs(inorder, postorder, i + 1, iend, pstart + i - istart, pend - 1);
    return root;
  }
};

int main(int argc, char **argv)
{
  int arr1[2] = {2, 1};
  int arr2[2] = {2, 1};

  vector<int> vec1(arr1 + 0, arr1 + 2);
  vector<int> vec2(arr2 + 0, arr2 + 2);

  Solution s;
  TreeNode *root = s.buildTree(vec1, vec2);
  cout << root -> val << endl;
  cout << root -> left -> val << endl;
}
