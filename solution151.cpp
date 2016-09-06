/**
 * Reverse Words in a String
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    stripSpaces(s);
    reverse(s.begin(), s.end());
    int i, j;
    for (i = 0, j =  0; j < s.size(); j ++ )
    {
      if (s[j] == ' ')
      {
	reverse(s.begin() + i, s.begin() + j);
	i = j + 1;
      }
    }
    reverse(s.begin() + i, s.end());
  }
  void stripSpaces(string &s)
  {
    // Remove leading spaces before a string
    while(s.size() > 0 && s[0] == ' ')
    {
      s.erase(0, 1);
    }
    s += ' ';
    // Remove center space
    for (int i = 0; i < s.size(); i ++)
    {
      while (s[i] == ' ' && s[i + 1] == ' ')
      {
	s.erase(i, 1);
      }
    }
    // Remove last space
    s.erase(s.size() - 1, 1);
  }
};

int main(int argc, char **argv)
{
  string str = "  the   sky     is blue    ";
  // string str = "";
  Solution s;
  s.reverseWords(str);
  cout << str << endl;
}
