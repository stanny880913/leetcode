#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int find(int i, vector<int> &map)
{
    if (i != map[i])
        map[i] = find(map[i], map);
    return map[i];
}
int smallest(int x, int y, int z)
{
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}
int minScore(int n, vector<vector<int>> &roads)
{
    vector<int> map(n + 1), minDistance(n + 1);

    // initialize
    for (int i = 1; i <= n; i++)
    {
        map[i] = i;
        minDistance[i] = INT16_MAX;
    }
    for (int i = 0; i < roads.size(); i++)
    {
        int root_a = find(roads[i][0], map), root_b = find(roads[i][1], map);
        int minPath = smallest(minDistance[root_a], minDistance[root_b], roads[i][2]);
        root_a > root_b ? map[root_a] = root_b : map[root_b] = root_a;
        minDistance[root_a] = minDistance[root_b] = minPath;
    }
    return minDistance[find(n, map)];
}

int main()
{
    vector<vector<int>> roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    int n = 4;
    minScore(n, roads);
    return 0;
}