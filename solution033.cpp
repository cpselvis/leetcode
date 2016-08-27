/**
 * Search in rotate array.
 * Binary search.
 *
 * cpselvis (cpselvis@gmail.com)
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
      int m = (l + r) >> 1;

      if (nums[m] == target)
      {
	return m;
      }	
      
      if (nums[l] <= nums[m])
      {
	if (target >= nums[l] && target < nums[m])
	{
	  r = m - 1;
	}
	else
	{
	  l = m + 1;
	}  
      }
      else
      {
	if (target > nums[m] && target <= nums[r])
	{
	  l = m + 1;  
	}
	else
	{
	  r = m - 1;
	}  
      }	
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int arr[7] = {0, 1, 2, 4, 5, 6, 7};
  vector<int> vec(arr + 0, arr + 7);
  cout << s.search(vec, 4) << endl;
}  
