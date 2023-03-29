#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int days_size = days.size(), costs_size = costs.size();
    vector<int> minCosts(days.back() + 1, 0);

    minCosts[0] = 0;

    for (int i = 1; i <= days.back(); i++)
    {
        for (auto day : days)
        {
            if (day != i) 
            {
                minCosts[i] = minCosts[i - 1];
                if (day > i)
                {
                    break;
                }
            }
            else
            {
                minCosts[i] = min({minCosts[i - 1] + costs[0], minCosts[max(0, i - 7)] + costs[1], minCosts[max(0, i - 30)] + costs[2]});
                break;
            }
        }

    }
    return minCosts.back();
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    mincostTickets(days, costs);
    return 0;
}