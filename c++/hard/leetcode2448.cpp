#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long minCost(vector<int> &nums, vector<int> &cost)
{
    vector<pair<long, long>> v;
    //long long cost_sum=0
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back({nums[i], cost[i]});
        //cost_sum += cost[i];
    }
    sort(v.begin(), v.end());

    long long cost_sum = accumulate(cost.begin(), cost.end(), 0LL);
    long long mid = (cost_sum + 1) / 2;
    long long temp;

    for (int i = 0; i < nums.size(); i++)
    {
        mid -= v[i].second;
        if (mid <= 0)
        {
            temp = v[i].first;
            break;
        }
    }
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += (long long)abs((long long)(temp - nums[i]) * (long long)cost[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};
    minCost(nums, cost);
    return 0;
}