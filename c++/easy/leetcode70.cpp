#include <vector>

using namespace std;

int climbStairs(int n)
{
  // . TLE(recursive)
  //   if(n == 0 || n == 1)
  //     return 1;

  //   return climbStairs(n-1) + climbStairs(n -2);
  if (n <= 3)
    return n;
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

int main()
{
  int n = 2;
  climbStairs(n);
  return 0;
}