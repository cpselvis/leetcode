/**
 * Spiral Matrix II
 *
 * cpselvis(cpselvis@gmail.com)
 * September 20th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix(n, vector<int>(n));

    if (n == 0)
    {
      return matrix;
    }

    int rowBegin = 0, rowEnd = n - 1;
    int colBegin = 0, colEnd = n - 1;

    int k = 1;
    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
      for (int i = colBegin; i <= colEnd; i ++)
      {
        matrix[rowBegin][i] = k ++;
      }
      rowBegin ++;

      for (int i = rowBegin; i <= rowEnd; i ++)
      {
	matrix[i][colEnd] = k ++;
      }
      colEnd --;

      if (rowBegin <= rowEnd)
      {
        for (int i = colEnd; i >= colBegin; i --)
        {
 	  matrix[rowEnd][i] = k ++;
        }
        rowEnd --;
      }

      if (colBegin <= colEnd)
      {
        for (int i = rowEnd; i >= rowBegin; i --)
        {
	  matrix[i][colBegin] = k ++;
        }
        colBegin ++;
      }
    }
    return matrix;
  }
};

int main(int argc, char **argv)
{
  Solution s;

  vector<vector<int> > matrix = s.generateMatrix(3);

  for (auto i : matrix)
  {
    for (auto j : i)
    {
      cout << j;
    }
    cout << endl;
  }
}
