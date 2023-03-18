/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory
{
    int current_index, size_index;
    vector<string> history;

public:
    BrowserHistory(string homepage)
    {
        current_index = -1;
        size_index = 0;
        visit(homepage);
    }

    void visit(string url)
    {
        ++current_index;
        if (current_index >= history.size())
        {
            history.push_back(url);
        }
        else
        {
            history[current_index] = url;
        }
        size_index = current_index;
    }

    string back(int steps)
    {
        current_index = max(0, current_index - steps);
        return history[current_index];
    }

    string forward(int steps)
    {
        current_index = min(size_index, current_index + steps);
        return history[current_index];
    }
};

// @lc code=end
