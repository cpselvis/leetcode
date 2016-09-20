/**
 * Find Peak Element
 * Binary search, theroy is base on mit course peak find course lecture 1.
 * (http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec01.pdf)
 * cpselvis(cpselvis@gmail.com)
 * September 20th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    
    int l = 0, r = nums.size() -1;

    while (l < r)
    {
      int mid = (l + r) >> 1;

      if (nums[mid] > nums[mid + 1])
      {
	r = mid;
      }
      else if (nums[mid] < nums[mid + 1])
      {
	l = mid + 1;
      }
    }
    return l;
  }
};

int main(int argc, char **argv)
{
  Solution s;

  int arr[1] = {1};
  vector<int> vec(arr + 0, arr + 1);

  cout << s.findPeakElement(vec) << endl;
}
