#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string s = "";
        for (int i = 0; i < strs.size(); ++i)
        {
            s += strs[i];
            s += "\t";
        }

        return s;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        string temp = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '\t')
            {
                result.push_back(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }

        return result;
    }
};
