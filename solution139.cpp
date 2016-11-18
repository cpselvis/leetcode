/**
 * Word Break
 *
 * cpselvis(cpselvis@gmail.com)
 * Nov 17th, 2016
 */

#include<iostream>
#include<unordered_set>
#include<memory.h>

using namespace std;

class Solution {
//private:
//unordered_set<string> memorized;
public:
  /** Consider two words case, simple case.
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    for (int i = 0;  i < s.size(); i ++)
    {
      string prefix = s.substr(0, i);

      if (wordDict.find(prefix) != wordDict.end())
      {
	string suffix = s.substr(i);

	if (wordDict.find(suffix) != wordDict.end())
	{
	  return true;
	}
      }
    }
    return false;
  }
  **/
  /* General solution, use iterative, this method is based on two words case.
  bool wordBreak(string s, unordered_set<string> &wordDict)
  {
    if (wordDict.find(s) != wordDict.end()) return true;

    if (memorized.find(s) != memorized.end()) return true;
    
    for (int i = 0; i < s.size(); i ++)
    {
      string prefix = s.substr(0, i);
      if (wordDict.find(prefix) != wordDict.end())
      {
	string suffix = s.substr(i);
	bool sub = wordBreak(suffix, wordDict);
	if (sub)
	{
	  memorized.insert(suffix);
	  return true;
	}
      }
    }
    return false;
  }
  */
  bool wordBreak(string s, unordered_set<string> &wordDict)
  {
    int size = s.size();
    bool dp[size + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= size; i ++)
    {
      for (int j = i - 1; j >= 0; j --)
      {
	if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
	{
	  dp[i] = true;
	}
      }
    }
    return dp[size];
  }
};


int main(int argc, char **argv)
{
  Solution s;
  unordered_set<string> wordDict;
  wordDict.insert("leet");
  wordDict.insert("code");
  wordDict.insert("word");
  wordDict.insert("problem");
  cout << s.wordBreak("leetcodewordproblem", wordDict) << endl;
}
