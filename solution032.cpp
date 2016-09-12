/**
 * Longest Valid Parentheses
 * stack
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 11th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> st;
    int ret = 0;
    int left = -1;

    for (int i = 0; i < s.size(); i ++)
    {
      if (s[i] == '(')
      {
	st.push(i);
      }
      else
      {
	if (st.empty())
	{
	  left = i;
	}
	else
	{
	  st.pop();

	  if (st.empty())
	  {
	    ret = max(ret, i - left);
	  }
	  else
	  {
	    ret = max(ret, i - st.top()); 
	  }
	}
      }
    }
    return ret;
  }
};


int main(int argc, char **argv)
{
  Solution s;
  cout << s.longestValidParentheses(")()())") << endl;
  cout << s.longestValidParentheses("()(())") << endl;
}
