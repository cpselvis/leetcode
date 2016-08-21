/**
 * Generate Parentheses
 *
 * cpselvis(cpselvis@gmail.com)
 * August 19th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    if (n > 0)
    {
      dfs(ret, n, n, "");
    }
    return ret;
  }
  void dfs(vector<string> &ret, int  p, int q, string str)
  {
    if (p == 0 && q == 0)
    {
      ret.push_back(str);
    }
    if (p > 0)
    {
      dfs(ret, p - 1, q, str + "(");
    }
    if (q > 0 && q > p)
    {
      dfs(ret, p, q - 1, str + ")");
    }  
  }    
};

int main(int argc, char **argv)
{
  Solution s;
  vector<string> ret = s.generateParenthesis(3);
  for (int i = 0; i < ret.size(); i ++)
  {
    cout << ret[i] << endl;
  }  
}
