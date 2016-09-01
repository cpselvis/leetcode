/**
 * Binary Tree Level Order Traversal 
 *
 * cpselvis(cpselvis@gmail.com)
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    vector<TreeNode*> nodes;

    if (root != NULL)
    {   
      nodes.push_back(root);
      dfs(nodes, ret);
    }  
    return ret;
  }

  void dfs(vector<TreeNode*> &nodes, vector<vector<int>> &ret)
  {
    vector<int> vals;
    vector<TreeNode*> childNodes;
    if (nodes.size() == 0)
    {
      return;
    }  
    for (int i = 0; i < nodes.size(); i ++)
    {
      if (nodes[i] != NULL)
      {
	vals.push_back(nodes[i] -> val);
        if (nodes[i] -> left != NULL)
	{  
          childNodes.push_back(nodes[i] -> left);
	}
	if (nodes[i] -> right != NULL)
	{
	  childNodes.push_back(nodes[i] -> right);
	}  
      }	
    }
    ret.push_back(vals);
    dfs(childNodes, ret);
  }
};

int main(int argc, char **argv)
{
  // Test
  //        3
  //      /  \
  //	 9   20
  //	    /  \
  //	   15   7
  TreeNode *root = new TreeNode(3);
  root -> left = new TreeNode(9);
  root -> right = new TreeNode(20);
  root -> right -> left = new TreeNode(15);
  root -> right -> right = new TreeNode(7);
  Solution s;
  vector<vector<int>> ret = s.levelOrder(root);
  for (auto i : ret)
  {
    cout << "Level start.." << endl;
    for (auto j : i)
    {
      cout << j << ' ';
    }
    cout << "Level end.." << endl;
  }
}
