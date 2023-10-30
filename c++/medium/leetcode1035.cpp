#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[n1][n2];
}

int main()
{
    vector<int> num1 = {2, 5, 1, 2, 5};
    vector<int> num2 = {10, 5, 2, 1, 5, 2};
    maxUncrossedLines(num1, num2);
    return 0;
}