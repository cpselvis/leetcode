/**
 * Next permutation.
 * Implements steps:
 *     Find largest index i where nums[i] < nums[i + 1]
 *     Find lasgest index j after i where nums[j] > nums[i]
 *     Swap node nums[i] and nums[j]
 *     Reverse from index i to the end.
 *
 * cpselvis(cpselvis@gmail.com)
 * August 31th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int i = n - 1;
    int j = n - 1;
    while (i > 0)
    {
      if (nums[i] > nums[i - 1])
      {
	while (j > i - 1)
	{
	  if (nums[j] > nums[i - 1])
	  {
	    swap(nums[i - 1], nums[j]);
	    reverse(nums.begin() + i, nums.end());
	    return;
	  }
	  j --;
	}  
      }
      i --;
    }
    reverse(nums.begin(), nums.end());
  }
};

int main(int argc, char **argv)
{
  int arr[3] = {1, 3, 2};
  vector<int> vec(arr + 0, arr + 3);
  Solution s;
  s.nextPermutation(vec);
  for (auto i : vec)
  {
    cout << i << endl;
  }
}  
