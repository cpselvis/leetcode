/**
 * @file  Container With Most Water
 * Two pointer.
 * 
 * cpselvis (cpselvis@gmail.com)
 * August 4, 2016 
 */
#include<cstdio>
#include<vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int max = 0, size = height.size(), area, distance, h, min;

    int i = 0, j = size - 1;

    while (i < j)
    {
      distance = j - i;
      if (height[i] < height[j])
      {
	min = height[i];
	i ++;
      }
      else
      {
	min = height[j];
	j --;
      }
      area = distance = distance * min;
      max = area > max ? area : max;
    }
    return max;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int arr[] = {1, 1};
  vector<int> v(arr + 0, arr + 2);
  printf("%d\n", s.maxArea(v));
}
