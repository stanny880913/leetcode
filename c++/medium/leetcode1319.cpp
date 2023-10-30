#include <iostream>
#include <vector>

using namespace std;

int find(int i, vector<int> &parent)
{
    if (parent[i] != i)
    {
        parent[i] = find(parent[i], parent);
    }
    return parent[i];
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    int group_num = n;
    int con_size = connections.size();
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < con_size; i++)
    {
        int parent_a = find(connections[i][0], parent), parent_b = find(connections[i][1], parent);
        if (parent_a != parent_b)
        {
            group_num--;
            parent[parent_a] = parent_b;
        }
    }
    return group_num - 1;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    int n = 4;
    makeConnected(n, connections);
    return 0;
}