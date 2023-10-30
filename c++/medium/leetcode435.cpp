#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareSecondElement(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size(), cnt = 0, prev = 0;
    sort(intervals.begin(), intervals.end(), compareSecondElement);

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= intervals[prev][1])
        {
            prev = i;
            cnt++;
        }
    }
    int ans = n - cnt - 1;
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    eraseOverlapIntervals(intervals);
    return 0;
}