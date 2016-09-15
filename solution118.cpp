/**
 * Pascal's Triangle
 *
 * cpselvis(cpselvis@gmail.com)
 * September 15th, 2016
 */
#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ret;
    for (int i = 0; i < numRows; i ++)
    {
      ret.push_back(vector<int>(i + 1, 1));
      for (int j = 1; j < i; j ++)
      {
	ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<vector<int> > ret = s.generate(5);

  for (auto i : ret)
  {
    cout << "start" << endl;
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
