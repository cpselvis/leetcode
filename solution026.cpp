/**
 * Remove Duplicates from Sorted Array
 *
 * cpselvis (cpselvis@gmail.com)
 * August 23th, 2016 
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int prev, len = 0;

    for (int i = 0; i < nums.size(); ) {
      if (nums[i] != prev) {
	len ++;
	prev = nums[i];
	i ++;
      } else {
	nums.erase(nums.begin() + i);
      }
    }
    return len;
  }
};


int main(int argc, char **argv)
{
  int arr[3] = {1, 1, 2};
  vector<int> nums(arr + 0, arr + 3);

  Solution s;
  cout << s.removeDuplicates(nums) << endl;
}  
