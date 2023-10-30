#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long minimumTime(vector<int> &time, int totalTrips)
{
    // bruce force(Time Limit Exceeded)
    // long long t = 1;

    // while (1)
    // {
    //     int trips = 0;
    //     for (int i = 0; i < time.size(); i++)
    //     {
    //         trips += (t / time[i]);
    //     }
    //     if (trips >= totalTrips)
    //     {
    //         return t;
    //     }
    //     t++;
    // }

    // Binary Search
    // 給死最大值
    // long long start = 1, end = 100000000000000;
    // 最大值不可能超過time array裏面的最小值*totalTrip，兩個值相乘代表需要多少時間完成
    long long minOneTripTime = *min_element(time.begin(), time.end());
    long long start = 1, end = long(minOneTripTime * totalTrips);

    while (start <= end)
    {
        long long trip = 0;
        // mid = totalTrips完成的時間
        // 必須最小化mid，因為題目要的ˊ是min time
        long long mid = (start + end) / 2;

        for (int i = 0; i < time.size(); i++)
        {
            trip += mid / time[i];
        }
        if (trip < totalTrips)
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
    vector<int> time = {1, 2, 3};
    int totalTrips = 5;
    minimumTime(time, totalTrips);
    return 0;
}