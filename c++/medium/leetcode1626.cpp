#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int playerNum = ages.size();
    vector<pair<int, int>> ageScorePair(playerNum);

    for (int i = 0; i < playerNum; i++)
    {
        ageScorePair[i].first = ages[i];
        ageScorePair[i].second = scores[i];
    }

    sort(ageScorePair.begin(), ageScorePair.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first == b.first ? a.second < b.second : a.first < b.first; });

    int ans = 0;
    vector<int> dp(playerNum, 0);

    for (int i = 0; i < playerNum; i++)
    {
        dp[i] = ageScorePair[i].second;
        ans = max(ans, dp[i]);
    }

    for (int i = 0; i < playerNum; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (ageScorePair[i].second >= ageScorePair[j].second)
            {
                dp[i] = max(dp[i], ageScorePair[i].second + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    vector<int> ages = {2, 1, 2, 1};
    vector<int> scores = {4, 5, 6, 5};
    bestTeamScore(scores, ages);
    return 0;
}

// 4,5,5,6
// 21,1,2

// Age 1,1,2,2
// Score 5,5,4,6

// Max 5+5=10
// 4<5 2>1 conflit
// 10+6 =16

// Age 1,8,9,10
// Score 5,1,2,3

// Max : 5
// 1+2+3=6 > 5
// Max 6

// 1. Sort age
// 2. Set a max for loop compare i && i-1 value if not conflict add to max

// Problem

// Age 1,6,7,8,9
// Score 1,20,3,19,30

// 1+20 =21+30=51 1,6,9
// 1+3+19+30=52 1,7,8,9

// 1. Create a list pair with age and score (AgeScroePair)
// 2. Sort age with AgeScorePair (if have same age then compare score, smaller score put in front)
// 3. Create a vector dp put the max score before this place (init with each score and set int answer with max score)
// 4. Use for loop to set dp value ( the inner loop compare if the person’s score with age is larger than other smaller age people)
// Important!!! set Dp array to be original value or add previous value
// dp=max(dp,dp[previous]+nowScore)