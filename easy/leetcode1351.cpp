#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] < 0)
                ans++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{5, 1, 0}, {-5, -5, -5}};
    countNegatives(grid);
    return 0;
}