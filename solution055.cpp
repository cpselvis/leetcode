/**
 * Jump Game
 *
 * cpselvis (cpselvis@gmail.com)
 * September 14th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
    {
      return false;
    }
    
    int maxJump = 0;
    for (int i = 0; i < n && i <= maxJump; i ++)
    {
      maxJump = max(maxJump, i + nums[i]);
    }
    return maxJump > n - 1;
  }
};

int main(int argc, char **argv)
{
  int arr[3] = {0, 2, 3};
  vector<int> nums(arr + 0, arr + 3);

  Solution s;
  cout << s.canJump(nums) << endl;
}
