/**
 * Add Binary
 *
 * cpselvis (cpselvis@gmail.com)
 * August 27th, 2016
 */

#include<iostream>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string ret = "";
    while (i >= 0 || j >= 0)
    {
      int tmp = carry;
      if (i >= 0)
      {
	tmp += a[i] - '0';
	i --;
      }
      if (j >= 0)
      {
	tmp += b[j] - '0';
	j --;
      }

      if (tmp >= 2)
      {
	tmp -= 2;
	carry = 1;
      }
      else
      {
	carry = 0;
      }
      ret = (tmp == 0 ? "0" : "1") + ret;
    }
    if (carry)
    {
      ret = "1" + ret;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.addBinary("11", "1") << endl;
}
