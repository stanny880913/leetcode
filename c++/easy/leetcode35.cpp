#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end+1;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    searchInsert(nums, target);
    return 0;
}
