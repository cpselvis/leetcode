/**
 * Number of Islands
 *
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char> >& grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i ++)
    {
      for (int j = 0; j < grid[i].size(); j ++)
      {
	if (grid[i][j] == '1')
	{
	  dfs(grid, i, j);
	  ret ++;
	}
      }
    }
    return ret;
  }

  void dfs(vector<vector<char> > &grid, int x, int y)
  {
    // Change point value.
    grid[x][y] = '0';
    // Four directions
    for (int dx = -1; dx <= 1; dx ++)
    {
      for (int dy = -1; dy <= 1; dy ++)
      {
	// Make sure directions is horizontally or vertically.
	if (dx != dy && dx != -dy)
	{
	  int nx = x + dx;
	  int ny = y + dy;
	  // Judge wether the point is in field and is adjacent to its neighbors.
	  if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1')
	  {
	    dfs(grid, nx, ny);
	  }
        }
      }
    }
  }
};

int main(int argc, char **argv)
{
  int arr1[5] = {'1', '1', '1', '1', '0'};
  int arr2[5] = {'1', '1', '0', '1', '0'};
  int arr3[5] = {'1', '1', '0', '0', '0'};
  int arr4[5] = {'0', '0', '0', '0', '0'};

  vector<vector<char> > vec;
  vector<char> vec1(arr1 + 0, arr1 + 5);
  vector<char> vec2(arr2 + 0, arr2 + 5);
  vector<char> vec3(arr3 + 0, arr3 + 5);
  vector<char> vec4(arr4 + 0, arr4 + 5);
  vec.push_back(vec1);
  vec.push_back(vec2);
  vec.push_back(vec3);
  vec.push_back(vec4);

  Solution s;
  cout << s.numIslands(vec)<< endl;
}
