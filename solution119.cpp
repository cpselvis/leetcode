/**
 * Pascal's Triangle II
 *
 * cpselvis(cpselvis@gmail.com)
 * September 15th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);

    for (int i = 2; i <= rowIndex; i ++)
    {
      for (int j = i - 1; j >= 1; j --)
      {
	row[j] = row[j] + row[j - 1];
      }
    }
    return row;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<int> ret = s.getRow(3);
  for (auto i : ret)
  {
    cout << i << endl;
  }
}
