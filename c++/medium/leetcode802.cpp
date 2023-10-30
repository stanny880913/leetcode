#include <vector>
#include <iostream>

using namespace std;

bool dfs(vector<vector<int>> &graph, int cur, vector<int> &color)
{
    if (color[cur] > 0)
        return color[cur] == 2;
    color[cur] = 1;
    for (int i : graph[cur])
    {
        if (color[i] == 2)
            continue;
        if (color[i] == 1 || !dfs(graph, i, color))
        {
            return false;
        }
    }
    color[cur] = 2;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> res, color(n); // 0 white, 1 gray, 2 black
    for (int i = 0; i < n; ++i)
    {
        if (dfs(graph, i, color))
            res.push_back(i);
    }
    return res;
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    eventualSafeNodes(graph);
    return 0;
}