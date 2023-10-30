#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool buddyStrings(string s, string goal)
{
    int n = s.size(), m = goal.size();
    set<char> temp(s.begin(), s.end());

    if (n != m)
        return false;
    if (s == goal && temp.size() < s.size())
        return true;

    vector<int> diff;
    for (int i = 0; i < n; i++)
    {
        if(s[i] != goal[i])
            diff.push_back(i);
    }

    if(diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]])
        return true;
    return 0;
}

int main()
{
    string s = "ab", goal = "ba";
    buddyStrings(s, goal);
    return 0;
}