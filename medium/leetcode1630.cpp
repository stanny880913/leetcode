#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    int n = l.size();
    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = l[i]; j <= r[i]; j++)
        {
            temp.push_back(nums[j]);
        }
        sort(temp.begin(), temp.end());

        int diff = temp[1] - temp[0];
        bool flag = true;

        for (int k = 2; k < temp.size(); k++)
        {
            if (temp[k] - temp[k - 1] != diff)
            {
                ans[i] = false;
                flag = false;
                break;
            }
        }
        if(flag == true)
            ans[i] = true;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};
    checkArithmeticSubarrays(nums, l, r);
    return 0;
}