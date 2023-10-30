#include <iostream>
#include <vector>

using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    // bruce force
    // int count_num = 1;

    // for (int i = 0; i <= arr.size() - 1; i++)
    // {
    //     while (count_num != arr[i])
    //     {
    //         k--;
    //         if (k == 0)
    //         {
    //             return count_num;
    //         }
    //         count_num++;
    //     }
    //     count_num++;
    // }
    // return count_num + k - 1;

    // binary search
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int less_number = arr[mid] - (mid + 1);

        if (less_number < k)
        {
            start = start + 1;
        }
        else
        {
            end = end - 1;
        }
    }
    return start + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    findKthPositive(arr, k);
    return 0;
}