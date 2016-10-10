/**
 * Shuffle an Array
 * Fisher–Yates Shuffle
 * 
 * cpselvis (cpselvis@gmail.com)
 * Oct 10th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
  vector<int> vec;
public:
  Solution(vector<int> nums) {
    vec = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return vec;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> ret = vec;
    int n = ret.size();
    for (int i = 0; i < n; i ++)
    {
      int t = rand() % n;
      swap(ret[i], ret[t]);
    }
    return ret;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
int main(int argc, char **argv)
{
  Solution *s = new Solution(vector<int>{1, 2, 3});

  vector<int> ret = s -> shuffle();

  for (auto i : ret)
  {
    cout << i << endl;
  }
}
