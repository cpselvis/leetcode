/**
 * Add Strings
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 17th, 2016
 */

class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    string ret = "";
    while (i >= 0 || j >= 0)
    {
      int tmp = carry;
      if (i >= 0)
      {
        tmp += num1[i] - '0';
	i --;
      }
      if (j >= 0)
      {
	tmp += num2[j] - '0';
	j --;
      }

      if (tmp > 9)
      {
	tmp -= 10;
	carry = 1;
      }
      else
      {
        carry = 0;
      }
      ret = to_string(tmp) + ret;
    }
    if (carry)
    {
      ret = "1" + ret;
    }
    return ret;
  }
};
