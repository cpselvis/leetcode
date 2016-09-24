/**
 * Search a 2D Matrix
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 24th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.empty()) return false;

    int lower = 0, upper = matrix.size() - 1;
    while (lower <= upper)
    {
      int mid = (lower + upper) >> 1;
      if (matrix[mid][0] == target) return true;
      else if (matrix[mid][0] < target)
      {
	lower = mid + 1;
      }
      else
      {
	upper = mid - 1;
      }
    }

    int row = upper;
    if (row < 0 || row > matrix.size() - 1) return false;
    lower = 0;
    upper = matrix[row].size() - 1;

    while (lower <= upper)
    {
      int mid = (lower + upper) >> 1;
      if (matrix[row][mid] == target) return true;
      else if (matrix[row][mid] < target)
      {
	lower = mid + 1;
      }
      else
      {
	upper = mid - 1;
      }
    }
    return false;
  }
};

int main(int argc, char **argv)
{
  vector<vector<int> > matrix({
      {1, 3, 5}
    });

  Solution s;

  cout << s.searchMatrix(matrix, 0) << endl;
}
