/**
 * @file Leetcode: Two sum.
 * 
 * @author cpselvis (cpselvis@gmail.com)
 * @date   2016.7.4
 */
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
      vector<int> output(2);
      unordered_map<int, int> umap;

      for (int i = 0, size = nums.size(); i < size; i ++)
      {
	if (umap.find(target - nums[i]) != umap.end())
	{
	  output[0] = umap[target - nums[i]];
	  output[1] = i;
	}
	else
	{
	  umap.insert(make_pair(nums[i], i));
	}
      }
      return output;
    }
};

// test
int main(int argc, char **argv)
{
  Solution s;
  int arr[] = {2, 7, 11, 15};
  int target = 13;
  vector<int> nums(arr, arr + 3);
  vector<int> output = s.twoSum(nums, target);
  printf("%d %d\n", output[0], output[1]);
}
