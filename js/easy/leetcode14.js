/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length == 0) {
    return "";
  }
  let ans = strs[0];
  let i = 1;
  while (i < strs.length) {
    if (!strs[i].startsWith(ans)) {
      ans = ans.slice(0, -1);
    } else {
      i++;
    }
  }
  return ans;
};
const strs = ["flower", "flow", "flight"];
longestCommonPrefix(strs);
