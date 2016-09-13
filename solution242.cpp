/**
 * Valid anagram.
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> umap;

    for (auto i : s)
    {
      umap[i] ++;
    }

    for (auto j : t)
    {
      if (umap.find(j) != umap.end())
      {
	umap[j] --;
      }
      else
      {
	return false;
      }
    }

    for (unordered_map<char, int>::iterator iter = umap.begin(); iter != umap.end(); iter ++)
    {
      if (iter -> second > 0)
      {
	return false;
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.isAnagram("anagram", "nagaram") << endl;
  cout << s.isAnagram("rat", "car") << endl;
}
