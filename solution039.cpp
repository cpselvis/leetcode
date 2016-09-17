/**
 * Combination Sum
 *
 * cpselvis(cpselvis@gmail.com)
 * September 17th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
      backtack(candidates, index, ret, sub, target - num);
      sub.pop_back();
    }
  }
};

int main(int argc, char **argv)
{
  int arr[4] = {2, 3, 6, 7};
  vector<int> vec(arr + 0, arr + 4);

  Solution s;
  vector<vector<int> > ret = s.combinationSum(vec, 7);

  for (auto i : ret)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
