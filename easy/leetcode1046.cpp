#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> q;
    for (int i = 0; i < stones.size(); i++)
    {
        q.push(stones[i]);
    }
    while (q.size() > 1)
    {
        int max = q.top();
        q.pop();
        int sec = q.top();
        q.pop();

        if (max - sec != 0)
            q.push(abs(max - sec));
    }
    int ans = q.size() == 1 ? q.top() : 0;
    return ans;
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    lastStoneWeight(stones);
    return 0;
}
