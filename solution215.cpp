/**
 * Kth Largest Element in an Array
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main(int argc, char **argv)
{
  int arr[6] = {3, 2, 1, 5, 6, 4};
  vector<int> vec(arr + 0, arr + 6);

  Solution s;
  cout << s.findKthLargest(vec, 2) << endl;
}

