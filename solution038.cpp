/**
 * Count and Say
 *
 * cpselvis(cpselvis@gmail.com)
 * September 12th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string ret = "1";
    for (int i = 1; i < n; i ++)
    {
      int count = 1;
      string tmp = "";
      for (int j = 1; j < ret.size(); j ++)
      {
	if (ret[j] == ret[j - 1])
	{
	  count ++;
	}
	else
	{
	  tmp += to_string(count);
	  tmp +=  ret[j - 1];
	  count = 1;
	}
      }
      tmp += to_string(count);
      tmp += ret[ret.size() - 1];
      ret = tmp;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.countAndSay(1) << endl;
  cout << s.countAndSay(2) << endl;
  cout << s.countAndSay(3) << endl;
  cout << s.countAndSay(4) << endl;
  cout << s.countAndSay(5) << endl;
}
