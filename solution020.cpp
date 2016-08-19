/**
 * Valid Parentheses
 * Stack
 * 
 * cpselvis(cpselvis@gmail.com)
 * August 19, 2016
 */
#include<iostream>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
    for (auto ch : s)
    {
      auto it = m.find(ch);
      if (it != m.end())
      {
        // If not find, then it's a closing parenthense.
        if (st.empty() || it -> second != st.top())
	{
          return false;
        }
	else
	{
	  st.pop();
	}  
      }
      else
      {
        // It's a opening parenthense.
        st.push(ch);
      }	
    }
    return st.empty();
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << "() :" << s.isValid("()") << endl;
  cout << "()[]{} :" << s.isValid("()[]{}") << endl;
  cout << "(] :" << s.isValid("(]") << endl;
  cout << "([)]" << s.isValid("([)]") << endl;
}  
