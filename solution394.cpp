/**
 * Decode String
 *
 * cpselvis(cpselvis@gmail.com)
 * September 7th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    return dfs(s, i);
  }
  string dfs(string s, int &i)
  {
    string ret = "";
    while (i < s.size() && s[i] != ']')
    {
      if (isdigit(s[i]))
      {
	int n = 0;
	while (i < s.size() && isdigit(s[i]))
	{
	  n = n * 10 + s[i ++] - '0';
	}
	i ++;
	string sub = dfs(s, i);
	i ++;
	while (n --)
	{
	  ret += sub;
	}
      }
      else
      {
	ret += s[i ++];
      }
    }
    return ret;
  }
};


int main(int argc, char **argv)
{
  Solution s;
  cout << s.decodeString("3[a]2[bc]") << endl;
  cout << s.decodeString("3[a2[c]]") << endl;
  cout << s.decodeString("2[abc]3[cd]ef") << endl;
}
