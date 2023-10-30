#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long mostPoints(vector<vector<int>> &questions)
{
    int q_size = questions.size();
    vector<long long> dp(q_size);

    for (int i = q_size - 1; i >= 0; i--)
    {
        long long solved = 0, skip = 0;
        if ((questions[i][1] + i + 1) < q_size)
        {
            solved = questions[i][0] + dp[questions[i][1] + i + 1];
        }
        else
        {
            solved = questions[i][0];
        }
        if (i != q_size - 1)
        {
            skip = dp[i + 1];
        }
        dp[i] = max(solved, skip);
    }
    return dp[0];
}

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    mostPoints(questions);
    return 0;
}