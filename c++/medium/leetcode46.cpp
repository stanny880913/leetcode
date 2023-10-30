#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> nums, int idx, vector<vector<int>> &ans)
{
  int n = nums.size();
  if (idx == n)
  {
    ans.push_back(nums);
    return;
  }
  for (int i = idx; i < n; i++)
  {
    swap(nums[i], nums[idx]);
    backtrack(nums, idx + 1, ans);
    swap(nums[i], nums[idx]);
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  // next_permutation
  // int n = nums.size();
  // vector<vector<int>> ans;
  // sort(nums.begin(),nums.end());
  // ans.push_back(nums);
  // while (next_permutation(nums.begin(), nums.end()))
  //   ans.push_back(nums);
  // return ans;

  // backtracking
  vector<vector<int>> ans;
  backtrack(nums, 0, ans);
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  permute(nums);
  return 0;
}