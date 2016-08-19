/**
 * Letter Combinations of a Phone Number
 * DFS
 *
 * cpselvis(cpselvis@gmail.com)
 * August 19, 2016
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.size() == 0)
    {
      return ret;
    }
    ret.push_back("");
    string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (int i = 0; i < digits.size(); i ++)
    {
      string letters = letterMap[digits[i] - '0'];
      vector<string> tmp;
      for (int j = 0; j < letters.size(); j ++)
      {
        for (int k = 0; k < ret.size(); k ++)
	{
          tmp.push_back(ret[k] + letters[j]);
        }  
      }
      ret = tmp;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<string> ret = s.letterCombinations("23");
  for (int i = 0; i < ret.size(); i ++)
  {
    cout << ret[i] << endl;
  }  
}
