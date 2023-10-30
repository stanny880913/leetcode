#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    vector<int> len(n, 1);
    vector<int> count(n, 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (len[j] + 1 > len[i])
                {
                    len[i] = len[j] + 1;
                    count[i] = 0;
                }

                if (len[j] + 1 == len[i])
                    count[i] += count[j];
            }
        }
    }

    int max_len = *max_element(len.begin(), len.end());

    for (int i = 0; i < n; i++)
    {
        if (len[i] == max_len)
            ans += count[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    findNumberOfLIS(nums);
    return 0;
}