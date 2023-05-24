#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> arr;
    long long curr_sum = 0;
    long long ans = 0;

    for (int i = 0; i < nums1.size(); i++)
        arr.push_back({nums2[i], nums1[i]});

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < k - 1; i++)
    {
        curr_sum += arr[i].second;
        pq.push(arr[i].second);
    }

    for (int i = k - 1; i < nums1.size(); i++)
    {
        curr_sum += arr[i].second;
        pq.push(arr[i].second);
        ans = max(ans, curr_sum * arr[i].first);
        curr_sum -= pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 3, 3, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    int k = 3;
    maxScore(nums1, nums2, k);
    return 0;
}