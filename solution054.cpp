/**
 * Spiral Matrix
 *
 * cpselvis(cpselvis@gmail.com)
 * September 20th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> ret;

    if (matrix.size() == 0)
    {
      return ret;
    }

    int rowBegin = 0, rowEnd = matrix.size() - 1;
    int colBegin = 0, colEnd = matrix[0].size() - 1;

    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {
      for (int i = colBegin; i <= colEnd; i ++)
      {
	ret.push_back(matrix[rowBegin][i]);
      }
      rowBegin ++;

      for (int i = rowBegin; i <= rowEnd; i ++)
      {
	ret.push_back(matrix[i][colEnd]);
      }
      colEnd --;

      if (rowBegin <= rowEnd)
      {
        for (int i = colEnd; i >= colBegin; i --)
        {
	  ret.push_back(matrix[rowEnd][i]);
        }
        rowEnd --;
      }

      if (colBegin <= colEnd)
      {
        for (int i = rowEnd; i >= rowBegin; i --)
        {
	  ret.push_back(matrix[i][colBegin]);
        }
        colBegin ++;
      }
    }

    return ret;
  }
};

int main(int argc, char **argv)
{
  vector<vector<int> > vec({
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  });

  Solution s;
  vector<int> ret = s.spiralOrder(vec);

  for (auto i : ret)
  {
    cout << i << endl;
  }
}
