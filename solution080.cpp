/**
 * Remove Duplicates from Sorted Array II
 *
 * cpselvis(cpselvis@gmail.com)
 * September 21th, 2016
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    unordered_map<int, int> umap;

    int ret = nums.size();
    for (int i = 0; i < nums.size(); )
    {
      if (umap[nums[i]] < 2)
      {
        umap[nums[i]] ++;
	i ++;
      }
      else
      {
	nums.erase(nums.begin() + i);
	ret --;
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int nums[6] = {1, 1, 1, 2, 2, 3};

  vector<int> vec(nums + 0, nums + 6);
  cout << s.removeDuplicates(vec) << endl;
}

