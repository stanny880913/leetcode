#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
  // int index = 0;
  // while (arr[index] < arr[index+1])
  // {
  //   index++;
  // }
  // return index;
  int l = 0, r = arr.size() - 1;

  while (l < r)
  {
    int mid = (l + r) / 2;
    if (arr[mid] < arr[mid + 1])
      l = mid + 1;
    else
      r = mid;
    }
  return l;
}

int main()
{
  vector<int> arr = {0, 10, 5, 2};
  peakIndexInMountainArray(arr);

  return 0;
}