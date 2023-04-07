#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minimizeArrayValue(vector<int> &nums)
{
    long long nums_size = nums.size();
    long long sum = 0, ans = 0;

    for (int i = 0; i < nums_size; i++)
    {
        sum += nums[i];
        long long av = (sum + i) / (i + 1);
        ans = max(ans, av);
    }
    return ans;
}

int main()
{
    vector<int> nums = {13, 13, 20, 0, 8, 9, 9};
    minimizeArrayValue(nums);
    return 0;
}