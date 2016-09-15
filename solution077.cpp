/**
 * Combinations
 *
 * cpselvis(cpselvis@gmail.com)
 * September 15th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ret;
    vector<int> sub;

    backtack(n, k, 1, ret, sub);
    return ret;
  }
  void backtack(int n, int k, int index, vector<vector<int> > &ret, vector<int> &sub)
  {
    if (k == 0)
    {
      ret.push_back(sub);
    }

    for (int i = index, j = k; i <= n; i ++, j = k)
    {
      sub.push_back(i);
      backtack(n, -- j, i + 1, ret, sub);
      sub.pop_back();
    }
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<vector<int> > ret = s.combine(4, 2);

  for (auto i : ret)
  {
    cout << "start:";
    for (auto j : i)
    {
      cout << j;
    }
    cout << endl;
  }
}
