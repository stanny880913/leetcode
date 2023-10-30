#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<int> ans;
    vector<int> visited(n);

    for (int i = 0; i < edges.size(); i++)
        visited[edges[i][1]]++;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    int n = 6;
    findSmallestSetOfVertices(n, edges);
    return 0;
}