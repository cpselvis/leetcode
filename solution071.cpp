/**
 * Simplify Path
 * 
 * cpselvis(cpselvis@gmail.com)
 * Nov 28th, 2016
 */
#include<iostream>
#include<stack>

using namespace std;


class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    string ret = "";
    
    for (int i = 0; i < path.size(); )
    {
      // Jump when meet character /
      while (path[i] == '/' && i < path.size())
	i ++;

      string s = "";
      while (path[i] != '/' && i < path.size())
      {
	s = s + path[i];
	i ++;
      }

      if (s == ".." && !st.empty())
	st.pop();
      else if (s != "" && s != "." && s != "..")
	st.push(s);
    }

    if (st.empty())
      ret = "/";

    while (!st.empty())
    {
      ret = "/" + st.top() + ret;
      st.pop();
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.simplifyPath("/..") << endl;
  cout << s.simplifyPath("/home/") << endl;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
}
