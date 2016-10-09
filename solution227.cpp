/**
 * Basic Calculator II
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 9th, 2016
 */
#include<iostream>
#include<stack>
#include<cctype>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    if (s.empty()) return 0;

    stack<int> st;
    int ret = 0, num = 0;
    char sign = '+';
    
    for (int i = 0; i < s.size(); i ++)
    {
      char ch = s[i];
      // If meet digit number.
      if (isdigit(ch))
      {
	num = num * 10 + ch - '0';
      }
      // Meet +,-,*,/ sign.
      if ((!isdigit(ch) && !isspace(ch)) || i == s.size() - 1)
      {
	if (sign == '+')
	{
	  st.push(num);
	}
	else if (sign == '-')
	{
	  st.push(-num);
	}
	else if (sign == '*' || sign == '/')
	{
	  int tmp = sign == '*' ? st.top() * num : st.top() / num;	  
	  st.pop();
	  st.push(tmp);
	}
	sign = s[i];
	num = 0;
      }
    }
    while (!st.empty())
    {
      ret += st.top();
      st.pop();
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.calculate("3+2*2") << endl;
  cout << s.calculate(" 3/2 ") << endl;
  cout << s.calculate(" 3+5 / 2 ") << endl;
}
