#include <iostream>
#include <vector>

using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    vector<int> ans;
    int result = 0;
    if (nums.size() == 1)
    {
        return 1;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[i + 1]);
        if (ans[0] == ans[1])
        {
            ans.clear();
            i++;
        }
        else
        {
            result = ans[0];
            break;
        }
    }
    return result;

    // method 2
    // int numsLen = nums.size(), index = 0;
    // while (index < numsLen - 1)
    // {
    //     int first = index, second = index + 1;
    //     if (nums[first] == nums[second])
    //     {
    //         index += 2;
    //         continue;
    //     }
    //     break;
    }
    return nums[index];
}

int main()
{
    vector<int> nums = {1, 1, 2};
    singleNonDuplicate(nums);
    return 0;
}