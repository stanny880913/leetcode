#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int start = nums[i];

        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
            i++;

        start == nums[i] ? ans.push_back(to_string(start)) : ans.push_back(to_string(start) + "->" + to_string(nums[i]));
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    summaryRanges(nums);
    return 0;
}