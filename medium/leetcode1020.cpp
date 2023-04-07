#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
    {
        return;
    }
    grid[i][j] = 0;

    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int numEnclaves(vector<vector<int>> &grid)
{
    int ans = 0, m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
            {
                dfs(grid, i, j);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    numEnclaves(grid);
    return 0;
}