/**
 * Contains Duplicate
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
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i ++)
    {
      umap[nums[i]] ++;
      if (umap[nums[i]] > 1)
      {
	return true;
      }
    }

    return false;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int arr[5] = {1, 1, 2, 3, 4};
  vector<int> vec(arr + 0, arr + 5);
  cout << s.containsDuplicate(vec) << endl;
}
