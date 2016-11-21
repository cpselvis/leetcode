/**
 * Top K Frequent Elements
 * 
 * cpselvis(cpselvis@gmail.com)
 * Nov 21th, 2016
 */


#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    priority_queue<pair<int, int> > pq;

    vector<int> ret;

    for (auto num : nums)
    {
      umap[num] ++;
    }

    for (unordered_map<int, int>::iterator iter = umap.begin(); iter != umap.end(); iter ++)
    {
      pq.push(make_pair(iter -> second, iter -> first));
    }

    while (k -- > 0)
    {
      ret.push_back(pq.top().second);
      pq.pop();
    }

    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  vector<int> ret = s.topKFrequent(nums, 2);

  for (auto i : ret)
  {
    cout << i << endl;
  }
}
