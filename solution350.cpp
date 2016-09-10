/**
 * Intersection of Two Arrays II
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 10th, 2016
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    unordered_map<int, int> umap;
    
    for (auto i : nums1)
    {
      umap[i] ++;
    }

    for (auto j : nums2)
    {
      if (umap.find(j) != umap.end() && umap[j] > 0)
      {
	ret.push_back(j);
	umap[j] --;
      }
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr1[4] = {1};
  int arr2[2] = {1, 1};

  vector<int> nums1(arr1 + 0, arr1 + 1);
  vector<int> nums2(arr2 + 0, arr2 + 2);

  Solution s;
  vector<int> ret = s.intersect(nums1, nums2);
  for (auto i : ret)
  {
    cout << i << endl;
  }
}
