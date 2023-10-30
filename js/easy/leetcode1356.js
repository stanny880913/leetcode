function sortByNumberOfOnes(arr) {
  // Create a map to store the number of 1's in each integer.
  const onesMap = new Map();
  for (const num of arr) {
    const onesCount = countOnes(num);
    if (!onesMap.has(onesCount)) {
      onesMap.set(onesCount, []);
    }
    onesMap.get(onesCount).push(num);
  }
  // Sort the array by the number of 1's in each integer.
  const sortedArr = [];
  for (const [onesCount, nums] of onesMap) {
    nums.sort();
    sortedArr.push(...nums);
  }
  return sortedArr;
}

// Counts the number of 1's in the binary representation of a given integer.
function countOnes(num) {
  let onesCount = 0;
  while (num > 0) {
    if (num & (1 === 1)) {
      onesCount++;
    }
    num >>= 1;
  }
  return onesCount;
}

const arr = [0, 1, 2, 3, 4, 5, 6, 7, 8];
const sortedArr = sortByNumberOfOnes(arr);

console.log(sortedArr); // [0, 1, 2, 4, 8, 3, 5, 6, 7]
