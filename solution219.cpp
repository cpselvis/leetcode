/** 
 * Contains Duplicate II
 *
 * cpselvis(cpselvis@gmail.com)
 * September 16th, 2016
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++)
    {
      if (umap[nums[i]] != 0 && i + 1 - umap[nums[i]] <= k)
      {
	return true;
      }
      umap[nums[i]] = i + 1;
    }
    return false;
  }
};

int main(int argc, char **argv)
{
  int arr[2] = {-1, -1};
  vector<int> vec(arr + 0, arr + 2);

  Solution s;
  cout << s.containsNearbyDuplicate(vec, 1) << endl;
}
