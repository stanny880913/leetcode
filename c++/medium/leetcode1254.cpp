#include <vector>
#include <iostream>
using namespace std;

bool dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
        return false;
    }
    if (grid[i][j] == 1)
    {
        return true;
    }
    grid[i][j] = 1;

    bool up = dfs(grid, i - 1, j);
    bool down = dfs(grid, i + 1, j);
    bool left = dfs(grid, i, j - 1);
    bool right = dfs(grid, i, j + 1);

    return up && down && left && right;
}

int closedIsland(vector<vector<int>> &grid)
{
    int count = 0;

    for (int i = 0; i < grid.size() - 1; i++)
    {
        for (int j = 0; j < grid[0].size() - 1; j++)
        {
            if (grid[i][j] == 0)
            {
                if (dfs(grid, i, j) == true)
                {
                    count += 1;
                }
                else
                {
                    count += 0;
                }
                // count += dfs(grid, i, j) ? 1 : 0;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
    closedIsland(grid);
    return 0;
}