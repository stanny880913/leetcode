#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &nums, int target)
{
  int n = nums.size();
  int left = 0, right = n - 1;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (nums[mid] == target)
      return true;

    if (nums[left] < nums[mid])
    {
      if (nums[left] <= target && target < nums[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    else if (nums[left] > nums[mid])
    {
      if (nums[mid] < target && target <= nums[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
    else
      left++;
  }
  return false;
}

int main()
{
  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  int target = 3;
  search(nums, target);
  return 0;
}