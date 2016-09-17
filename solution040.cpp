/**
 * Combination Sum II
 *
 * cpselvis(cpselvis@gmail.com)
 * September 17th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > ret;
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    backtack(candidates, 0, ret, sub, target);
    return ret;
  }

  void backtack(vector<int> &candidates, int index, vector<vector<int> > &ret, vector<int> &sub, int target)
  {
    if (target == 0)
    {
      ret.push_back(sub);
    }
    for (; index < candidates.size() && candidates[index] <= target; index ++)
    {
      int num = candidates[index];
      sub.push_back(num);
      backtack(candidates, index + 1, ret, sub, target - num);
      sub.pop_back();

      // Avoid duplicate situations.
      while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1])
      {
	index ++;
      }
    }
  }
};

int main(int argc, char **argv)
{
  int arr[7] = {10, 1, 2, 7, 6, 1, 5};
  vector<int> vec(arr + 0, arr + 7);

  Solution s;
  vector<vector<int> > ret = s.combinationSum2(vec, 8);

  for (auto i : ret)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
