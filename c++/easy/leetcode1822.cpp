#include <iostream>
#include <vector>

using namespace std;

int arraySign(vector<int> &nums)
{
    int negative = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            return 0;

        else if (nums[i] < 0)
            negative++;
    }
return (negative % 2 == 1) ? -1 : 1;
}

int main()
{
    vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};
    arraySign(nums);
    return 0;
}