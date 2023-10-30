#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int profit_len = profits.size();
    vector<pair<int, int>> dic;
    priority_queue<int> queue;
    int i = 0;

    for (int i = 0; i < profit_len; i++)
    {
        dic.push_back({capital[i], profits[i]});
    }
    sort(dic.begin(), dic.end());
    while (k--)
    {
        while (i < profit_len && dic[i].first<=w)
        {
            queue.push(dic[i].second);
            i++;
        }

        if (queue.empty())
        {
            break;
        }
        else
        {
            w += queue.top();
            queue.pop();
        }
    }

    return w;
}

int main()
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    findMaximizedCapital(k, w, profits, capital);
    return 0;
}