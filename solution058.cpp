/**
 * Length of Last Word
 *
 * cpselvis (cpselvis@gmail.com)
 * September 1st, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int ret = 0;
    s = stripSpace(s);
    int i = s.size();
    while (i > 0)
    {
      if (s[--i] != ' ')
      {
	ret ++;
      }
      else
      {
	break;
      }
    }
    return ret;
  }
  string stripSpace(string s)
  {
    int i = s.size() - 1;

    while (i >= 0 && s[i] == ' ')
    {
      i --;
    }
    return s.substr(0, i + 1);
  }  
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.lengthOfLastWord("a   ") << endl;
  cout << s.lengthOfLastWord("Hello world") << endl;
}
