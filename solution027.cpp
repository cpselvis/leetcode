/**
 * Remove Element
 *
 * cpselvis(cpselvis@gmail.com)
 * August 24th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int i;
    for (i = 0; i < nums.size(); )
    {
      if (nums[i] == val)
      {
	nums.erase(nums.begin() + i);
      }
      else
      {
	i ++;
      }	
    }
    return i;
  }
};

int main(int argc, char **argv)
{
  int arr[4] = {3, 2, 2, 3};

  vector<int> nums(arr + 0, arr + 4);
  Solution s;
  cout << s.removeElement(nums, 3) << endl;
}  
