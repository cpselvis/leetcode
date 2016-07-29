/**
 * @file Median of two sorted arrays.
 *
 * cpselvis(cpselvis@gmail.com)
 * 2016.7.29
 */

#include<cstdio>
#include<vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();

    if ((size1 + size2) % 2 == 0)
    {
      return (findKth(nums1, nums2, (size1 + size2) / 2) + findKth(nums1, nums2, (size1 + size2) / 2 + 1)) / 2;
    }
    else
    {
      return findKth(nums1, nums2, (size1 + size2 + 1) / 2);
    }
  }

  // Merge and count to find Kth of two sorted arrays.
  double findKth(vector<int>& nums1, vector<int>& nums2, int k)
  {
    int p = 0, q = 0;               // Two pointers fo vector
    int size1 = nums1.size(), size2 = nums2.size();
    for (int i = 0; i < k - 1; i ++)
    {
      // Overflow case.
      if (p >= size1)
      {
	q ++;
      }
      else if (q >= size2)
      {
	p ++;
      }	
      else if (nums1[p] <= nums2[q])
      {
	p ++;
      }
      else
      {
	q ++;
      }	
    }
    if (p >= size1)
    {
      return nums2[q];
    }
    else if (q >= size2)
    {
      return nums1[p];
    }
    else
    {
      return min(nums1[p], nums2[q]);
    }
  }  
};

int main(int argc, char **argv)
{
  int arr1[] = {1, 3};
  int arr2[] = {2, 4, 6, 8, 10};

  vector<int> nums1(arr1 + 0, arr1 + 2);
  vector<int> nums2(arr2 + 0, arr2 + 5);

  Solution s;
  double result = s.findMedianSortedArrays(nums1, nums2);

  printf("%f\n", result);
}
