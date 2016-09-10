/**
 * Search for a Range
 * 
 * cpselvis(cpselvis@gmail.com) 
 * September 11th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    vector<int> ret(2, -1);
    while (nums[l] < nums[r])
    {
      int m = (l + r) / 2;
      if (nums[m] < target)
      {
        l = m + 1;
      }
      else if (nums[m] > target)
      {
        r = m - 1;
      }
      else
      {
        if (nums[l] == target)
	{
	  r --;
	}
        else
	{
	  l ++;
	}
      }
    }

    if (nums[l] == target || nums[r] == target)
    {
      ret[0] = l;
      ret[1] = r;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr[2] = {1, 4};
  vector<int> vec(arr + 0, arr + 2);

  Solution s;
  vector<int> ret = s.searchRange(vec, 4);
  for (auto i : ret)
  {
    cout << i << endl;
  }
}
