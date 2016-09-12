/**
 * Group Anagrams
 * HashTable
 *
 * cpselvis(cpselvis@gmail.com)
 * September 12th, 2016
 */
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    multimap<string, string> mmap;
    vector<vector<string> > ret;
    for (auto str : strs)
    {
      string s = str;
      sort(s.begin(), s.end());
      mmap.insert(pair<string, string>(s, str));
    }

    for (multimap<string, string>::iterator iter = mmap.begin(); iter != mmap.end();)
    {
      int count = mmap.count(iter -> first);
      vector<string> tmp;

      for (int i = 0; i < count; i ++, iter ++)
      {
	tmp.push_back(iter -> second);
      }
      ret.push_back(tmp);
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  string arr[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> strs(arr + 0, arr + 6);

  Solution s;
  vector<vector<string> > ret = s.groupAnagrams(strs);

  for (auto i : ret)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
