#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double new21Game(int n, int k, int maxPts)
{
    double sumW = 1.0, ans = 0.0;

    if (k == 0 || n >= k - 1 + maxPts)
        return 1.0;

    vector<double> dp(n + 1);

    // dp[0] = 1.0;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = sumW / maxPts;
        (i < k) ? sumW += dp[i] : ans += dp[i];

        if (i - maxPts >= 0)
            sumW -= dp[i - maxPts];
    }
    return ans;
}

int main()
{
    int n = 4, k = 3, maxPts = 4;
    new21Game(n, k, maxPts);
    return 0;
}