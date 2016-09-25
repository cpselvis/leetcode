/**
 * Two Sum II - Input array is sorted 
 *
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    vector<int> ret;
    
    while (i < j)
    {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
      {
	ret.push_back(i + 1);
	ret.push_back(j + 1);
	break;
      }
      else if (sum < target)
      {
	i ++;
      }
      else
      {
	j --;
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  vector<int> nums({-3, 3, 4, 90});
  Solution s;

  vector<int> ret = s.twoSum(nums, 0);
  for (auto i : ret)
  {
    cout << i << endl;
  }
}
