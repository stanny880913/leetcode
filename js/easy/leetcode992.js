/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParityII = function (nums) {
  const odd = [];
  const even = [];
  const ans = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] % 2 == 1) {
      odd.push(nums[i]);
    } else {
      even.push(nums[i]);
    }
  }
  for (let i = 0; i < nums.length; i++) {
    if (i % 2 == 1) {
      ans.push(odd.pop());
    } else {
      ans.push(even.pop());
    }
  }
  console.log(ans);
  return ans;
};

const arr = [4,2,5,7];
sortArrayByParityII(arr);