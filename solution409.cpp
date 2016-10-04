/**
 * Longest Palindrome
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 4th, 2016
 */
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<int, int> umap;

    for (int i = 0; i < s.size(); i ++)
    {
      umap[s[i]] ++;
    }

    int maxLen = 0;
    bool hasOdd = false;
    for (unordered_map<int, int>::iterator iter = umap.begin(); iter != umap.end(); iter ++)
    {
      int snd = iter -> second;
      if (snd >= 2)
      {
	maxLen += snd;
	if (snd % 2 != 0)
	{
	  maxLen -= 1;
	  hasOdd = true;
	}
      }
      else
      {
	hasOdd = true;
      }
    }
    if (hasOdd)
    {
      maxLen += 1;
    }
    return maxLen;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.longestPalindrome("abccccdd") << endl;
}
