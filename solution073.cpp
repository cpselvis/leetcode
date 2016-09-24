/**
 * Set Matrix Zeroes
 *
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> >& matrix) {
    if (matrix.empty()) return;

    bool rowZero = false, columnZero = false;        // Variable to record wether first row and first column has zero number.

    for (int i = 0; i < matrix[0].size(); i ++)
    {
      if (matrix[0][i] == 0)
      {
	rowZero = true;
      }
    }

    for (int i = 0; i < matrix.size(); i ++)
    {
      if (matrix[i][0] == 0)
      {
	columnZero = true;
      }
    }

    for (int i = 1; i < matrix.size(); i ++)
    {
      for (int j = 1; j < matrix[0].size(); j ++)
      {
	if (matrix[i][j] == 0)
	{
	  matrix[0][j] = 0;
	  matrix[i][0] = 0;
	}
      }
    }

    for (int i = 1; i < matrix.size(); i ++)
    {
      for (int j = 1; j < matrix[0].size(); j ++)
      {
	if (matrix[i][0] == 0 || matrix[0][j] == 0)
	{
	  matrix[i][j] = 0;
	}
      }
    }

    if (rowZero)
    {
      for (int i = 0; i < matrix[0].size(); i ++)
      {
	matrix[0][i] = 0;
      }
    }
    if (columnZero)
    {
      for (int i = 0; i < matrix.size(); i ++)
      {
	matrix[i][0] = 0;
      }
    }
  }
};

int main(int argc, char **argv)
{
  
}
