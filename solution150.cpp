/**
 * Evaluate Reverse Polish Notation
 *
 * cpselvis(cpselvis@gmail.com)
 * September 4th, 2016
 */
#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i ++)
    {
      if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
      {
	st.push(atoi(tokens[i].c_str()));
      }	
      else
      {
	int num1 = st.top();
	st.pop();
	int num2 = st.top();
	st.pop();
	int tmp;
	if (tokens[i] == "+")
	{  
	  tmp = num2 + num1;
        }
        else if (tokens[i] == "-")
	{
	  tmp = num2 - num1;
	}
	else if (tokens[i] == "*")
	{  
	  tmp = num2 * num1;
	}
	else if (tokens[i] == "/")
	{
          tmp = num2 / num1;
	}
	st.push(tmp);
      }
    }
    return st.top();
  }
};

int main(int argc, char **argv)
{
  string arr[5] = {"2", "1", "+", "3", "*"};
  vector<string> vec(arr + 0, arr + 5);

  Solution s;
  cout << s.evalRPN(vec) << endl;
}
