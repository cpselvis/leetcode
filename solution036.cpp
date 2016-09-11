/**
 * Valid Sudoku
 *
 * cpselvis(cpselvis@gmail.com)
 * September 12th, 2016
 */
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    unordered_map<int, int> rows[9];
    unordered_map<int, int> columns[9];
    unordered_map<int, int> grids[9];

    for (int i = 0; i < board.size(); i ++)
    {
      for (int j = 0; j < board[i].size(); j ++)
      {
	if (board[i][j] != '.')
	{
	  rows[i][board[i][j]] ++;
	  if (rows[i][board[i][j]] > 1)
	  {
	    return false;
	  }

	  columns[j][board[i][j]] ++;
	  if (columns[j][board[i][j]] > 1)
	  {
	    return false;
	  }

	  int p = i/3 * 3 + j/3;
	  grids[p][board[i][j]] ++;
	  if (grids[p][board[i][j]] > 1)
	  {
	    return false;
	  }
	}
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  char arr1[9] = {'.', '.', '.', '.', '5', '.', '.', '1', '.'};
  char arr2[9] = {'.', '4', '.', '3', '.', '.', '.', '.', '.'};
  char arr3[9] = {'.', '.', '.', '.', '.', '3', '.', '.', '1'};
  char arr4[9] = {'8', '.', '.', '.', '.', '.', '.', '2', '.'};
  char arr5[9] = {'.', '.', '2', '.', '7', '.', '.', '.', '.'};
  char arr6[9] = {'.', '1', '5', '.', '.', '.', '.', '.', '.'};
  char arr7[9] = {'.', '.', '.', '.', '.', '2', '.', '.', '.'};
  char arr8[9] = {'.', '2', '.', '9', '.', '.', '.', '.', '.'};
  char arr9[9] = {'.', '.', '4', '.', '.', '.', '.', '.', '.'};

  vector<char> vec1(arr1 + 0, arr1 + 9);
  vector<char> vec2(arr2 + 0, arr2 + 9);
  vector<char> vec3(arr3 + 0, arr3 + 9);
  vector<char> vec4(arr4 + 0, arr4 + 9);
  vector<char> vec5(arr5 + 0, arr5 + 9);
  vector<char> vec6(arr6 + 0, arr6 + 9);
  vector<char> vec7(arr7 + 0, arr7 + 9);
  vector<char> vec8(arr8 + 0, arr8 + 9);
  vector<char> vec9(arr9 + 0, arr9 + 9);
  
  vector<vector<char> > vec;
  vec.push_back(vec1);
  vec.push_back(vec2);
  vec.push_back(vec3);
  vec.push_back(vec4);
  vec.push_back(vec5);
  vec.push_back(vec6);
  vec.push_back(vec7);
  vec.push_back(vec8);
  vec.push_back(vec9);

  Solution s;
  cout << s.isValidSudoku(vec) << endl;
}
