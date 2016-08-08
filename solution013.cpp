/**
 * @file  Roman to integer.
 *
 * cpselvis (cpselvis@gmail.com)
 * August 8, 2016
 */
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> umap;
    umap.insert(make_pair('I', 1));
    umap.insert(make_pair('V', 5));
    umap.insert(make_pair('X', 10));
    umap.insert(make_pair('L', 50));
    umap.insert(make_pair('C', 100));
    umap.insert(make_pair('D', 500));
    umap.insert(make_pair('M', 1000));

    int output = 0, last = 0, current;
    for (int i = 0; i < s.length(); i ++)
    {
      if (umap.find(s[i]) != umap.end())
      {
	current = umap[s[i]];
	output += current;
	if (current > last)
	{
	  output -= 2 * last;
	}
	last = current;
      }
    }

    return output;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.romanToInt("DCXXI") << endl;
  cout << s.romanToInt("IMCLVI") << endl;
}
