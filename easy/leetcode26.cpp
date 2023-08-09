#include <vector>
#include <map>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int ans = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == nums[i - 1])
    {
      nums[ans] = nums[i];
      ans++;
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  removeDuplicates(nums);
  return 0;
}