#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> myMap;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }
        for (auto it = myMap.begin(); it != myMap.end(); it++)
        {
            maxHeap.push({it->second, it->first});
        }
        for (int i = 0; i < k; i++)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
