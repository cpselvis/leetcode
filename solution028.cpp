/**
 * Implement strStr()
 * KMP algorithm, build next table. 
 * To calculate next value, we need to find a string which has property that it is longest prefix string as well as suffix string.
 *
 * cpselvis (cpselvis@gmail.com)
 * August 24th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int j = 0;
    vector<int> next(needle.size());

    if ((haystack.size() == 0 && needle.size() == 0) || needle.size() == 0)
    {
      return 0;
    }  
    buildNextTable(needle, next);
    for (int i = 0; i < haystack.size(); i ++)
    {
      while (j > 0 && haystack[i] != needle[j])
      {
	j = next[j - 1];
      }
      if (haystack[i] == needle[j])
      {
	j ++;
      }
      else
      {
	j = 0;
      }

      if (j == needle.size())
      {
	return i - j + 1;
      }
    }
    return -1;
  }

  /**
   * @brief Build next table.
   *        Next table is longest prefix and suffix length of each index.
   */
  void buildNextTable(string needle, vector<int> &next)
  {
    next[0] = 0;
    for (int i = 1; i < needle.size(); i ++)
    {
      int tmp = next[i - 1];
      while (tmp && needle[tmp] != needle[i])
      {
	tmp = next[tmp - 1];
      }
      if (needle[tmp] == needle[i])
      {
	next[i] = tmp + 1;
      }
      else
      {
	next[i] = 0;
      }
    }
  }  
};

int main(int argc, char **argv)
{
  Solution s;

  // Test build next table function.
  // string str = "agctagcagctagctg";
  //vector<int> vec(17);
  //s.buildNextTable(str, vec);
  //for (auto i : vec)
  //{
  //  cout << i << endl;
  // }
  cout << s.strStr("", "a") << endl;
  cout << s.strStr("a", "") << endl;
  cout << s.strStr("", "") << endl;
  cout << s.strStr("helloworld", "world") << endl;
  cout << s.strStr("aaa", "aa") << endl;
  cout << s.strStr("mississippi", "issip") << endl;
  cout << s.strStr("aaabaaabbbabaa", "babb") << endl;
}  
