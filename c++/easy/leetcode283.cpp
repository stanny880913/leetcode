#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int len = nums.size(), temp = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] != 0)
            swap(nums[temp++], nums[i]);
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    return 0;
}