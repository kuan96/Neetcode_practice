#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<set<char>> rows(9);
        vector<set<char>> columns(9);
        vector<set<char>> sub_boxes(9);

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char ch = board[i][j];
                if (ch == '.')
                    continue;

                int subBox_index = i / 3 + (j / 3) * 3;
                bool duplicates_in_row = rows[i].find(ch) != rows[i].end();
                bool duplicates_in_col = columns[j].find(ch) != columns[j].end();
                bool duplicates_in_subBox = sub_boxes[subBox_index].find(ch) != sub_boxes[subBox_index].end();

                if (duplicates_in_row || duplicates_in_col || duplicates_in_subBox)
                    return false;

                rows[i].insert(ch);
                columns[j].insert(ch);
                sub_boxes[subBox_index].insert(ch);
            }
        }

        return true;
    }
};

/*

0   1   2
3   4   5
6   7   8

*/