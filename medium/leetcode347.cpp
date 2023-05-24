#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> map;
    for (auto i : nums)
    {
        map[i]++;
    }

    vector<pair<int, int>> temp;
    for (auto i = map.begin(); i != map.end(); i++)
    {
        temp.push_back(make_pair(i->first, i->second));
    }
    sort(temp.begin(), temp.end(), sortByVal);

    temp.erase(temp.begin() + k, temp.end());
    vector<int> ans;

    for (auto key : temp)
    {
        ans.push_back(key.first);
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    int k = 2;
    topKFrequent(nums, k);
    return 0;
}