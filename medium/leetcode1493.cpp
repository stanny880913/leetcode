#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    vector<int> zeros;
    zeros.push_back(-1);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            zeros.push_back(i);
    }

    if (zeros.size() < 2)
        return n - 1;

    zeros.push_back(n);

    for (int i = 1; i < zeros.size() - 1; i++)
    {
        int currLen = zeros[i + 1] - zeros[i - 1] - 2;
        ans = max(ans, currLen);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    longestSubarray(nums);
    return 0;
}