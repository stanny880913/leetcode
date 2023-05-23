#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    // visited value
    // 0 = un-visited, 1 = a set, 2 = b set
    int n = graph.size();
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 0)
            continue;

        // BFS to visited  neighbors
        queue<int> q({i});
        visited[i] = 1;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int v : graph[cur])
            {
                if (visited[v] == 0)
                {
                    visited[v] = visited[cur] + 1;
                    q.push(v);
                }
                else if (visited[v] == visited[cur])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    isBipartite(graph);
    return 0;
}
