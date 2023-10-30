#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
                else
                    continue;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9; // [0,1]
    // vector<int> nums = {3,2,4}; int target = 6; // [1,2]
    // vector<int> nums = {3,3}; int target = 6; // [0,1]
    Solution s;
    vector<int> ans = s.twoSum(nums, target);
    cout << "[" << ans[0] << "," << ans[1] << "]\n";
    return 0;
}