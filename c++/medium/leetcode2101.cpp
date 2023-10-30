#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int start, vector<int> &visited, vector<int> graph[], int &cnt)
{
    visited[start] = 1;
    cnt++;
    for (auto temp : graph[start])
    {
        if (!visited[temp])
            dfs(temp, visited, graph, cnt);
    }
}

int maximumDetonation(vector<vector<int>> &bombs)
{
    int ans = 0;
    vector<int> graph[bombs.size()];

    for (int i = 0; i < bombs.size(); i++)
    {
        for (int j = 0; j < bombs.size(); j++)
        {
            if (i == j)
                continue;

            float dist_x = bombs[j][0] - bombs[i][0];
            float dist_y = bombs[j][1] - bombs[i][1];
            float r1 = bombs[i][2];

            float dist = dist_x * dist_x + dist_y * dist_y;
            if (dist <= r1 * r1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < bombs.size(); i++)
    {
        vector<int> visited(bombs.size());
        int cnt = 0;
        dfs(i, visited, graph, cnt);
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    maximumDetonation(bombs);
    return 0;
}