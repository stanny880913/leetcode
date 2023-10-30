#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

// Create a table of combinations
vector<vector<long long>> generateComb(int n)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }
    return dp;
}

// Count the number of binary search trees
int countBST(vector<int> &nums, vector<vector<long long>> &dp)
{
    if (nums.size() <= 2)
        return 1;

    int root = nums[0];
    vector<int> left, right;

    for (int i = 1; i < nums.size(); ++i)
        nums[i] < root ? left.push_back(nums[i]) : right.push_back(nums[i]);

    long long leftCount = left.size();
    long long rightCount = right.size();

    long long numWays = (dp[leftCount + rightCount][leftCount] * countBST(left, dp)) % MOD;
    numWays = (numWays * countBST(right, dp)) % MOD;

    return numWays;
}

// Calculate the number of binary search trees (main function)
int numOfWays(vector<int> &nums)
{
    vector<vector<long long>> dp = generateComb(nums.size());
    return (countBST(nums, dp) - 1 + MOD) % MOD;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    numOfWays(nums);
    return 0;
}