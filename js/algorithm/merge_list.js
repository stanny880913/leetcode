function merge(list1, list2) {
  const merge_list = [];
  let i = 0;
  let j = 0;
  while (i < list1.length && j < list2.length) {
    if (list1[i] <= list2[j]) {
      merge_list.push(list1[i]);
      i++;
    } else {
      merge_list.push(list2[j]);
      j++;
    }
  }
  while (i < list1.length) {
    merge_list.push(list1[i]);
    i++;
  }
  while (j < list2.length) {
    merge_list.push(list2[j]);
    j++;
  }
  return merge_list;
}

const list1 = [1, 3, 5];
const list2 = [];
const ans = merge(list1, list2);
console.log(ans);
