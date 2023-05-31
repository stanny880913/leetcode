#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
            nums[temp++] = nums[i];
    }
    return temp;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    removeElement(nums, val);
    return 0;
}