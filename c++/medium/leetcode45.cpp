#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    int ans = 0, now = 0, prev = 0;
    // now為當前index可以走的最遠距離
    // prev為上一個index可以走的最遠距離
    for (int i = 0; i < nums.size() - 1; i++)
    {
        now = max(now, i + nums[i]);
        if (i == prev)
        {
            ans++;
            prev = now;
            if (now >= nums.size())
            {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{2,3,1,1,4};
    jump(nums);
    return 0;
}