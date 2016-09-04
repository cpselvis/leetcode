/**
 * Binary Tree Level Order Traversal II
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 4th, 2016
 */
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    vector<TreeNode*> nodes;

    if (root != NULL)
    {
      nodes.push_back(root);
      dfs(nodes, ret);
    }
    reverse(ret.begin(), ret.end());
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
