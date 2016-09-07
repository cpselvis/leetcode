/**
 * Rotate Array
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    while (k --)
    {
      int tmp = nums[n - 1];
      nums.erase(nums.end() - 1);
      nums.insert(nums.begin(), tmp);
    }
  }
};

int main(int argc, char **argv)
{
  int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> nums(arr + 0, arr + 7);
  Solution s;
  s.rotate(nums, 3);
  for (auto i : nums)
  {
    cout << i << endl;
  }
}
