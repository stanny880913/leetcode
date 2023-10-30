#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<vector<pair<int, double>>> graph(n);
    priority_queue<pair<double, int>> pq;

    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0], y = edges[i][1];
        graph[x].push_back({y, succProb[i]});
        graph[y].push_back({x, succProb[i]});
    }

    vector<double> vis(n, 0);
    pq.push({1, start});

    while (!pq.empty())
    {
        double prob = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_node == end)
            return prob;

        for (auto i : graph[curr_node])
        {
            if (prob * i.second > vis[i.first])
            {
                vis[i.first] = prob * i.second;
                pq.push({vis[i.first], i.first});
            }
        }
    }
    return 0;
}

int main()
{
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    maxProbability(n, edges, succProb, start, end);
    return 0;
}