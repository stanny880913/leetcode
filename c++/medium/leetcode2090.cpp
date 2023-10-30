#include <vector>
#include <iostream>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
    vector<int> avg;
    long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        avg.push_back(sum);
    }

    vector<int> ans(nums.size(),-1);
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < k || i >= nums.size() - k)
            continue;
        else
            ans[i] = (avg[i + k] - avg[i - k] + nums[i - k]) / (2 * k + 1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    getAverages(nums, k);
    return 0;
}