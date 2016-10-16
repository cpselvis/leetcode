/**
 * Isomorphic Strings
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 16th, 2016
 */
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> umap1;
    unordered_map<char, char> umap2;

    for (int i = 0; i < s.size(); i ++)
    {
      if (umap1.find(s[i]) != umap1.end() && umap1[s[i]] != t[i])
      {
	return false;
      }
      if (umap2.find(t[i]) != umap2.end() && umap2[t[i]] != s[i])
      {
	return false;
      }
      umap1[s[i]] = t[i];
      umap2[t[i]] = s[i];
    }
    return true;
  }
};


int main(int argc, char **argv)
{
  Solution s;
  cout << s.isIsomorphic("egg", "add") << endl;
  cout << s.isIsomorphic("foo", "bar") << endl;
  cout << s.isIsomorphic("paper", "title") << endl;
}
