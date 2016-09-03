/**
 * Multiply Strings
 *
 * cpselvis(cpselvis@gmail.com)
 * September 3th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    string ret = "";
    int l1 = num1.size();
    int l2 = num2.size();

    vector<int> v1(l1);
    vector<int> v2(l2);
    vector<int> v3(l1 + l2);
    if (num1 == "0" || num2 == "0")
    {
      return "0";
    }  
    for (int i = 0; i < l1; i ++)
    {
      v1[l1 - i - 1] = num1[i] - '0';
    }

    for (int j = 0; j < l2; j ++)
    {
      v2[l2 - j - 1] = num2[j] - '0';
    }

    for (int i = 0; i < l1; i ++)
    {
      for (int j = 0; j < l2; j ++)
      {
	v3[i + j] += v1[i] * v2[j];
	if (v3[i + j] >= 10)
	{
	  v3[i + j + 1] += v3[i + j] / 10;
	  v3[i + j] %= 10;
	}  
      }
    }

    for (int i = v3.size() - 1; i >= 0; i --)
    {
      if (i != v3.size() - 1 || (i == v3.size() - 1 && v3[i] != 0))
      {
        ret += v3[i] + '0';
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.multiply("2", "2") << endl;
  cout << s.multiply("12", "12") << endl;
  cout << s.multiply("111", "111") << endl;
  cout << s.multiply("123", "456") << endl;
}



