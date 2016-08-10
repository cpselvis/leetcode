/**
 * @brief Longest Common Prefix
 *
 * cpselvis(cpselvis@gmail.com)
 * August 8th, 2016
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
    {
      return "";
    }
    for (int i = 0; i < strs[0].size(); i ++)
    {
      for (int j = 0; j < strs.size(); j ++)
      {
	if (strs[j].size() < i + 1 || strs[j][i] != strs[0][i])
	{
	  return strs[0].substr(0, i);
	}  
      }	
    }
    return strs[0];
  }
};

int main(int argc, char **argv)
{
  Solution s;
  string arr[] = {"abcde", "abc", "abde", "abedc"};
  vector<string> strs(arr + 0, arr + 4);
  cout << s.longestCommonPrefix(strs) << endl;
}
