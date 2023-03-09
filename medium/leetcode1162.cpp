#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxDistance(vector<vector<int>> &grid)
{
    int ans = 0, gridsize = grid.size();
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<vector<int>> q;
    for (int i = 0; i < gridsize; ++i)
    {
        for (int j = 0; j < gridsize; ++j)
        {
            if (grid[i][j] == 0)
            {
                continue;
            }
            q.push(vector<int>{i, j});
        }
    }
    if (q.size() == 0 || q.size() == gridsize * gridsize)
    {
        return -1;
    };
    while (!q.empty())
    {
        ans++;
        for (int k = q.size(); k > 0; k--)
        {
            auto head = q.front();
            q.pop();
            for (auto dir : dirs) // dir會依照{-1, 0}, {0, 1}, {1, 0}, {0, -1}下去跑
            {
                int rowDir = head[0] + dir[0], colDir = head[1] + dir[1];
                if (rowDir < 0 || rowDir >= gridsize || colDir < 0 || colDir >= gridsize || grid[rowDir][colDir] == 1)
                {
                    continue;
                }
                grid[rowDir][colDir] = 1;
                q.push({rowDir, colDir});
            }
        }
    }
    return ans - 1;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    maxDistance(grid);
    return 0;
}