#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{
    // int start = 1;
    // //如果最大值都無法在時限內吃完，那打從一開始就吃不完所有香蕉了
    // int end = *max_element(piles.begin(), piles.end());
    // while (start < end)
    // {
    //     int mid = start + (end - start) / 2;
    //     int countHours = 0;
    //     for (int i = 0; i < piles.size(); i++)
    //     {
    //         countHours += (piles[i] + mid - 1) / mid;
    //     }
    //     if (countHours <= h)
    //     {
    //         end = mid;
    //     }
    //     else
    //     {
    //         start = mid + 1;
    //     }
    // }
    // return start;

    int start = 1;
    // 如果最大值都無法在時限內吃完，那打從一開始就吃不完所有香蕉了
    int end = *max_element(piles.begin(), piles.end());
    // if (h == piles.size())
    // {
    //     return end;
    // }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int countHour = 0;
        bool overTime = false;

        for (int i = 0; i < piles.size(); i++)
        {
            countHour += piles[i] / mid;

            if (piles[i] % mid != 0)
            {
                countHour++;
            }
            if (countHour > h)
            {
                overTime = true;
                break;
            }
        }
        if (overTime)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

int main()
{
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    minEatingSpeed(piles, h);
    return 0;
}