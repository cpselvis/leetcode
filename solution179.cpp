/**
 * Largest Number
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  string largestNumber(vector<int>& nums) {
    string ret = "";
    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size(); i ++)
    {
      ret += to_string(nums[i]);
    }
    if (ret[0] == '0')
    {
      return "0";
    }
    return ret;
  }
  static bool compare(int a, int b)
  {
    string x = to_string(a);
    string y = to_string(b);
    
    return x + y > y + x;
  }
};

int main(int argc, char **argv)
{
  //  int arr[5] = {3, 30, 34, 5, 9};
  //vector<int> nums(arr + 0, arr + 5);

  int arr[2] = {0, 0};
  vector<int> nums(arr + 0, arr + 2);
  Solution s;
  cout << s.largestNumber(nums) << endl;
}
