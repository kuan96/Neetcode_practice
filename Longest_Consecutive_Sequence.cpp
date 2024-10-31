#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int result = 0;
        int tmp = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] - nums[i - 1] == 1)
                tmp++;
            else
                tmp = 0;

            result = max(result, tmp);
        }

        return result + 1;
    }
};

// nums=[9,1,4,7,3,-1,0,5,8,-1,6]
// -1 -1 0 1 3 4 5 6 7 8 9
