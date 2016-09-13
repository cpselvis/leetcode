/**
 * Unique Paths
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0)
    {
      return 0;
    }
    
    vector<vector<int> > dp(m, vector<int>(n));

    dp[0][0] = 1;
    for (int i = 1; i < n; i ++)
    {
      dp[0][i] = 1;
    }

    for (int j = 1; j < m; j ++)
    {
      dp[j][0] = 1;
    }

    for (int i = 1; i < n; i ++ )
    {
      for (int j = 1; j < m; j ++)
      {
	dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};


int main(int argc, char **argv)
{
  Solution s;

  cout << s.uniquePaths(3, 7) << endl;
}
