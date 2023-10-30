#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> ans1;
    vector<int> ans2;

    for (auto num : set1)
    {
        if (set2.count(num) == 0)
        {
            ans1.push_back(num);
        }
    }

    for (auto num : set2)
    {
        if (set1.count(num) == 0)
        {
            ans2.push_back(num);
        }
    }
    return {ans1, ans2};
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    findDifference(nums1, nums2);
    return 0;
}