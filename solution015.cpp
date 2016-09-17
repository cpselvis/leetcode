/**
 * 3Sum
 * Two pointer, time complexity is O(n^2))
 *
 * cpselvis(cpselvis@gmail.com)
 * September 17th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ret;
    int n = nums.size();

    if (n < 3)
    {
      return ret;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i ++)
    {
      // Avoid repeate situation.
      if (i > 0 && nums[i] == nums[i - 1])
      {
	continue;
      }
      int l = i + 1, r = n - 1;

      while (l < r)
      {
	int sum = nums[i] + nums[l] + nums[r];
	if (sum == 0)
	{
	  ret.push_back(vector<int>{nums[i], nums[l], nums[r]});

	  // Avoid repeate elements.
	  while (nums[l] == nums[l + 1])
	  {
	    l ++;
	  }
	  while (nums[r] == nums[r - 1])
	  {
	    r --;
	  }
	  l ++;
	  r --;
	}
	else if (sum > 0)
	{
	  r --;
	}
	else
	{
	  l ++;
	}
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> vec(arr + 0, arr + 6);

  Solution s;
  vector<vector<int> > ret = s.threeSum(vec);
  for (auto i : ret)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
