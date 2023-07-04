#include <vector>
#include <map>
using namespace std;

int singleNumber(vector<int> &nums)
{
    map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    for (int j = 0; j < nums.size(); j++)
    {
        if (map[nums[j]] == 1)
            return nums[j];
    }
    return 0;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    singleNumber(nums);
    return 0;
}