#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, curr_sum = 0;
    int ans = __INT32_MAX__;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];

        while (curr_sum >= target)
        {
            ans = min(ans, i - left + 1);
            curr_sum -= nums[left++];
        }
    }

    return ans == __INT32_MAX__ ? 0 : ans;
}

int main()
{
    int target = 7;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    minSubArrayLen(target, nums);
    return 0;
}