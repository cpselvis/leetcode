/**
 * Construct Binary Tree from Preorder and Inorder Traversal
 *
 * cpselvis(cpselvis@gmail.com)
 * September 5th, 2016
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }

  TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, int pstart, int pend, int istart, int iend)
  {
    if (istart > iend)
    {
      return NULL;
    }
    TreeNode *root = new TreeNode(preorder[pstart]);

    int i;
    for (i = istart; i < iend; i ++)
    {
      if (preorder[pstart] == inorder[i])
      {
	break;
      }
    }
    root -> left = dfs(preorder, inorder, pstart + 1, pstart + i - istart, istart, i - 1);
    root -> right = dfs(preorder, inorder, pstart + i + 1 - istart, pend, i + 1, iend);
    return root;
  }
};

int main(int argc, char **argv)
{  
  int arr1[] = {4, 2, 1, 3, 5, 7, 6};
  int arr2[] = {1, 2, 3, 4, 5, 6 ,7};

  vector<int> pre(arr1 + 0, arr1 + 7);
  vector<int> in(arr2 + 0, arr2 + 7);

  Solution s;
  TreeNode *root = s.buildTree(pre, in);
  cout << root -> val << endl;
  cout << root -> left -> val << endl;
  cout << root -> right -> val << endl;
}
