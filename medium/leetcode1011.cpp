#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int left = *max_element(weights.begin(), weights.end());   // max of weights
    int right = accumulate(weights.begin(), weights.end(), 0); // total of weights

    while (left < right)
    {
        int mid = (right + left) / 2;
        int need_days = 1, current_weights = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (current_weights + weights[i] > mid)
            {
                need_days++;
                current_weights = 0;
            }
            current_weights += weights[i];
        }
        if (need_days > days)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int main()
{
    vector<int> weights = {3, 2, 2, 4, 1, 4};
    int days = 3;
    shipWithinDays(weights, days);

    return 0;
}