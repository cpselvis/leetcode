/**
 * Find the Difference
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<int, int> umap;
    char ret;
    
    for (auto i : s)
    {
      umap[i] ++;
    }

    for (auto j : t)
    {
      if (umap.find(j) != umap.end() && umap[j] > 0)
      {
	umap[j] --;
      }
      else
      {
	ret = j;
	break;
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.findTheDifference("abcd", "abcde") << endl;
}
