#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size(), ans = 1;

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        if (current.first == n - 1 && current.second == n - 1)
        {
            ans = grid[current.first][current.second];
            return ans;
        }

        for (auto dir : dirs)
        {
            int dir_x = dir.first + current.first;
            int dir_y = dir.second + current.second;

            if (dir_x < n && dir_y < n && dir_x >= 0 && dir_y >= 0 && grid[dir_x][dir_y] == 0)
            {
                q.push({dir_x, dir_y});
                grid[dir_x][dir_y] = grid[current.first][current.second] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    shortestPathBinaryMatrix(grid);
    return 0;
}