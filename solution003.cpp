/**
 * @file Leetcode: Longest Substring Without Repeating Characters
 *
 * cpselvis (cpselvis@gmail.com)
 * 2016.7.4
 */
#include<cstdio>
#include<string>

using namespace std;
// Use hash map.
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int hash[256];

    int maxLen = 0, distance, i, j;
    if (s.length() == 1)
    {
      return 1;
    }
    for (i = 0; i < s.length(); i ++)
    {
      memset(hash, 0, sizeof(hash));
      hash[s[i]] = 1;

      for (j = i + 1; j < s.length(); j ++)
      {
	if (hash[s[j]] == 0)
	{	  
	  hash[s[j]] = 1;
	}
	else
	{
	  distance = j - i;
	  maxLen = distance > maxLen ? distance : maxLen;
	  break;
	}
      } 

      if (j == s.length() && j - i > maxLen)
      {
        maxLen = j - i;
      }	
    }
    return maxLen;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
  printf("%d\n", s.lengthOfLongestSubstring("bbbbb"));
  printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));
  printf("%d\n", s.lengthOfLongestSubstring("bwf"));
}
