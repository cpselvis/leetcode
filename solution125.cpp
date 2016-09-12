/**
 * Valid Palindrome
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.size() == 0)
    {
      return true;
    }

    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
      if (!isLetterOrDigit(s[i]))
      {
	i ++;
      }
      else if (!isLetterOrDigit(s[j]))
      {
	j --;
      }
      else
      {
	if (tolower(s[i]) != tolower(s[j]))
        {
	  return false;
        }
      
        i ++;
        j --;
      }
    }
    return true;
  }
  bool isLetterOrDigit(char ch)
  {
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
      return true;
    }
    return false;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << s.isPalindrome("race a car") << endl;
  cout << s.isPalindrome(".,") << endl;
}
