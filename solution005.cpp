/**
 * Longest Palindromic Substring
 * DP algorithm, suppose s(j, i) stand for substring which index is from j to i,
 * dp[i][j] stands for which this substring is palindrome or not.
 * Transform function expression:
 *                      s[i][j]                            (i - j < 2)
 *        dp[j][i] = {  
 *                      s[i-1] == s[j +1] && d[i-1][j+1]   (i - j >= 2)
 * 
 * cpselvis (cpselvis@gmail.com)
 * September 10th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    // Note: don't use vector, when s.size() >= 1000, it will cause time limited exceed
    //    vector<vector<int> > dp(1000, vector<int>(1000, false));

    bool dp[1000][1000];
    memset(dp, 0, sizeof(dp));
    int start = 0;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i ++)
    {
      for (int j = 0; j <= i; j ++)
      {
	if (i - j < 2)
	{
	  dp[j][i] = s[i] == s[j];
	}
	else
	{
	  dp[j][i] = s[i] == s[j] && dp[j + 1][i - 1];
	}
	if (dp[j][i] && i - j + 1 > maxLen)
	{
	  maxLen = i - j + 1;
	  start = j;
	}
      }
    }
    return s.substr(start, maxLen);
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.longestPalindrome("a") << endl;
  cout << s.longestPalindrome("abbaabccba") << endl;
}
