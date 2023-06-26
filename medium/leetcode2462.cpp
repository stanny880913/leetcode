#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long totalCost(vector<int> &costs, int k, int candidates)
{
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int left = 0, right = costs.size() - 1;

    while (k--)
    {
        while (pq1.size() < candidates && left <= right)
        {
            pq1.push(costs[left]);
            left++;
        }

        while (pq2.size() < candidates && left <= right)
        {
            pq2.push(costs[right]);
            right--;
        }

        int top1 = pq1.size() > 0 ? pq1.top() : INT32_MAX;
        int top2 = pq2.size() > 0 ? pq2.top() : INT32_MAX;

        if (top1 <= top2)
        {
            ans += top1;
            pq1.pop();
        }
        else
        {
            ans += top2;
            pq2.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k = 3, candidates = 4;
    totalCost(costs, k, candidates);
    return 0;
}