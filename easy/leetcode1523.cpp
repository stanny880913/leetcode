#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countOdds(int low, int high)
{
    // method 1
    // int odd = 0;
    // for (int i = low; i <= high; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         odd++;
    //     }
    // }
    // return odd;

    // method 2
    // int odd = (high - low) / 2;

    // if (high % 2 != 0 || low % 2 != 0)
    // {
    //     odd++;
    // }
    // return odd;

    // method 3
    return (high + 1) / 2 - (low) / 2;
}

int main()
{
    int low = 8;
    int high = 10;
    countOdds(low, high);
    return 0;
}