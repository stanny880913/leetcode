#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adjust_list, int &reverse, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (auto neighbor : adjust_list[node])
    {
        if (!visited[abs(neighbor)])
        {
            if (neighbor < 0)
            {
                reverse += 1;
            }
            else
            {
                reverse += 0;
            }
            dfs(adjust_list, reverse, visited, abs(neighbor));
        }
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    int reverse = 0;
    vector<vector<int>> adjust_list(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < connections.size(); i++)
    {
        int from = connections[i][0];
        int to = connections[i][1];

        adjust_list[from].push_back(-to);
        adjust_list[to].push_back(from);
    }
    dfs(adjust_list, reverse, visited, 0);
    return reverse;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    minReorder(n, connections);
    return 0;
}