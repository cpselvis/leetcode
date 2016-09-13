/**
 * Minimum Path Sum
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (m == 0 || n == 0)
    {
      return 0;
    }

    vector<vector<int> > dp(m, vector<int>(n));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i ++)
    {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j ++)
    {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i ++)
    {
      for (int j = 1; j < n; j ++)
      {
	dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main(int argc, char **argv)
{
  
}
