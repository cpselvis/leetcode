/**
 * Find Minimum in Rotated Sorted Array
 *
 * cpselvis(cpselvis@gmail.com)
 * September 16th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    return find(nums, 0, nums.size() - 1);
  }

  int find(vector<int> &nums, int left, int right)
  {
    if (nums[left] <= nums[right])
    {
      return nums[left];
    }
    int mid = (left + right) >> 1;

    if (nums[mid] > nums[right])
    {
      return find(nums, mid + 1, right);
    }
    return find(nums, left, mid);
  }
};

int main(int argc, char **argv)
{
  int arr[6] = {3, 4, 5, 6, 1 ,2};
  vector<int> vec(arr + 0, arr + 6);
  
  Solution s;
  cout << s.findMin(vec) << endl;
}
