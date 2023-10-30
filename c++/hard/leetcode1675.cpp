#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <stdint.h>

using namespace std;

int minimumDeviation(vector<int> &nums)
{
    priority_queue<int> queue; // store even number
    int m = INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            queue.push(nums[i]);
            m = min(m, nums[i]);
        }
        else
        {
            queue.push(nums[i] * 2);
            m = min(m, nums[i] * 2);
        }
    }

    while (!queue.empty())
    {

        ans = min(ans, queue.top() - m);
        if (queue.top() % 2 != 0)
        {
            break;
        }
        m = min(m, queue.top() / 2);
        queue.push(queue.top() / 2);
        queue.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    minimumDeviation(nums);
    return 0;