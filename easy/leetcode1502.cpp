#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

int main()
{
    vector<int> arr = {3, 5, 1};
    canMakeArithmeticProgression(arr);
    return 0;
}