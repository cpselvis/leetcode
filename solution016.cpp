/**
 * 3Sum Closest
 *
 * cpselvis(cpselvis@gmail.com)
 * September 17th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int closet = nums[0] + nums[1] + nums[2];

    int diff = abs(closet - target);

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i ++)
    {
      int left = i + 1;
      unsigned long right = nums.size() - 1;

      while (left < right)
      {
        int newCloset = nums[i] + nums[left] + nums[right];
	int newDiff = abs(newCloset - target);

        if (diff > newDiff)
        {
	  diff = newDiff;
	  closet = newCloset;
	}

	if (newCloset < target)
	{
	  left ++;
	}
	else
	{
	  right --;
	}
      }
    }

    return closet;
  }
};

int main(int argc, char **argv)
{
  int arr[4] = {0, 2, 1, -3};
  vector<int> vec(arr + 0, arr + 4);
  Solution s;
  cout << s.threeSumClosest(vec, 1) << endl;
}
