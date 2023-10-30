#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long zeroFilledSubarray(vector<int> &nums)
{
    int num_size = nums.size();

    long long ans = 0, count = 0;

    for (int i = 0; i < num_size; i++)
    {
        if (nums[i] == 0)
        {   
            count++;
            ans += count;
        }
        else
        {
            count = 0;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    zeroFilledSubarray(nums);
    return 0;
}