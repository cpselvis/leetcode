/**
 * Climbing Stairs
 * DP
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n);

    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i ++ )
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.climbStairs(2) << endl;
  cout << s.climbStairs(5) << endl;
}
