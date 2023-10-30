#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSubsequence(vector<int> &arr, int difference)
{
    int ans = 0, n = arr.size();
    unordered_map<int, int> dp;

    for (int i = 0; i < n; i++)
    {
        dp[arr[i]] = 1 + dp[arr[i] - difference];
        ans = max(dp[arr[i]], ans);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;
    longestSubsequence(arr, difference);
    return 0;
}