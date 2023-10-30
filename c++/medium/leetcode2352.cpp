#include <vector>
#include <iostream>
#include <map>
using namespace std;

// map
int equalPairs(vector<vector<int>> &grid)
{
    int ans = 0;
    map<vector<int>, int> map;
    // grid[i] = rows
    for (int i = 0; i < grid.size(); i++)
    {
        map[grid[i]]++;
    }

    for (int j = 0; j < grid[0].size(); j++)
    {
        vector<int> column;
        for (int i = 0; i < grid.size(); i++)
        {
            column.push_back(grid[i][j]);
        }
        ans += map[column];
    }
    return ans;
}

//Brute Force 
// int equalPairs(vector<vector<int>> &grid)
// {
//     int ans = 0;
//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid.size(); j++)
//         {
//             int k = 0;
//             for (k = 0; k < grid.size(); k++)
//             {   
//                 int temp1 = grid[i][k];
//                 int temp2 = grid[k][j];
//                 if (temp1 != temp2)
//                     break;
//             }
//             if (k == grid.size())
//                 ans++;
//         }
//     }
//     return ans;
// }

int main()
{
    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    equalPairs(grid);
    return 0;
}