/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  var mySet = new Set();
  var ans = 0;
  var i = 0;
  var j = 0;

  while (i < s.length) {
    if (!mySet.has(s[i])) {
      mySet.add(s[i]);
      i++;
    } else {
      ans = Math.max(ans, mySet.size);
      mySet.delete(s[j]);
      j++;
    }
  }
  ans = Math.max(ans, mySet.size);
  console.log(ans);
  return ans;
};

const s = "abcabcbb";
lengthOfLongestSubstring(s);
