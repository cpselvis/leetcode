/**
 * Merge Sorted Array
 * From right most to left. 
 *
 * cpselvis (cpselvis@gmail.com)
 * August 30th, 2016
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, p = m + n - 1;

    while (p >= 0)
    {
      if (i < 0)
      {
        nums1[p] = nums2[j --];
      }
      else if (j < 0)
      {
	nums1[p] = nums1[i --];
      }
      else if (nums1[i] >= nums2[j])
      {
        nums1[p] = nums1[i --];
      }
      else
      {
	nums1[p] = nums2[j --];
      }
      p --;
    }
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int b[] = {2, 4, 6, 8, 10};
  vector<int> vec1(a + 0, a + 10);
  vector<int> vec2(b + 0, b + 5);
  s.merge(vec1, 5, vec2, 5);

  for (auto i : vec1)
  {
    cout << i << endl;
  }  
}  

