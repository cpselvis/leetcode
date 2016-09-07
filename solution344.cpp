/**
 * Reverse String
 *
 * cpselvis(cpselvis@gmail.com)
 * September 7th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
      i ++;
      j --;
    }
    return s;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.reverseString("hello") << endl;
}
