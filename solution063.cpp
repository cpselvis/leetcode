/**
 * Unique Paths II
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (m == 0 || n == 0 || obstacleGrid[0][0] == 1)
    {
      return 0;
    }

    vector<vector<int> > dp(m, vector<int>(n, 0));

    dp[0][0] = 1;
    
    for (int i = 1; i < m; i ++)
    {
      if (obstacleGrid[i][0] == 1 || dp[i - 1][0] == 0)
      {
	dp[i][0] = 0;
      }
      else
      {
	dp[i][0] = 1;
      }
    }

    for (int j = 1; j < n; j ++)
    {
      if (obstacleGrid[0][j] == 1 || dp[0][j - 1] ==0)
      {
	dp[0][j] = 0;
      }
      else
      {
	dp[0][j] = 1;
      }
    }

    for (int i = 1; i < m; i ++)
    {
      for (int j = 1; j < n; j ++)
      {
        if (obstacleGrid[i][j] == 0)
	{
	  dp[i][j] += dp[i - 1][j];
	}
	if (obstacleGrid[i][j] == 0)
	{
	  dp[i][j] += dp[i][j - 1];
	}
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main(int argc, char **argv)
{

}
