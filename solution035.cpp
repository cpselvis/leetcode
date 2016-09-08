/**
 * Search Insert Position
 * Binary search algorith.
 *
 * cpselvis(cpselvis@gmail.com)
 * September 8th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int lower = 0, upper = nums.size() - 1;
    
    while (lower < upper)
    {
      int mid = (lower + upper) >> 1;
      if (nums[mid] < target)
      {
	lower = mid + 1;
      }
      else if (nums[mid] > target)
      {
	upper = mid - 1;
      }
      else
      {
	return mid;
      }
    }
    return nums[lower] < target ? lower + 1 : lower;
  }
};

int main(int argc, char **argv)
{
  int arr[4] = {1, 3, 5, 6};
  vector<int> nums(arr + 0, arr + 4);
  Solution s;
  cout << s.searchInsert(nums, 5) << endl;
  cout << s.searchInsert(nums, 2) << endl;
  cout << s.searchInsert(nums, 7) << endl;
  cout << s.searchInsert(nums, 0) << endl;
}
