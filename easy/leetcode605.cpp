#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
    {
        return true;
    }

    int bed_size = flowerbed.size();

    for (int i = 0; i < bed_size; i++)
    {
        if (i - 1 >= 0 && flowerbed[i - 1] == 1)
            continue;
        if (i + 1 < bed_size && flowerbed[i + 1] == 1)
            continue;

        if (flowerbed[i] == 0)
        {
            flowerbed[i] = 1;
            --n;
        }
        if (n <= 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> flowervbed = {1, 0, 0, 0, 0, 1};
    int n = 2;
    canPlaceFlowers(flowervbed, n);
    return 0;
}
