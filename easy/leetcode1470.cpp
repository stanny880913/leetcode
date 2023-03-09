#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.emplace_back(nums[i]);
        ans.emplace_back(nums[i + n]);
    }
    return ans;
};

int main()
{
    vector<int>nums = {1,1,2,2};
    int n = 2;
    shuffle(nums,n);
}
