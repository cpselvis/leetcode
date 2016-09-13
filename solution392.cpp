/**
 * Is Subsequence
 * Greedy
 * 
 * cpselvis(cpselvis@gmail.com) 
 * September 13th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int idx = 0;

    for (int i = 0; i < t.size(); i ++)
    {
      if (s[idx] == t[i])
      {
	idx ++;
      }
    }
    return idx == s.size();
  }
};

int main(int argc, char **argv)
{
  Solution s;

  cout << s.isSubsequence("abc", "ahbgdc") << endl;
  cout << s.isSubsequence("axc", "ahbgdc") << endl;
}
