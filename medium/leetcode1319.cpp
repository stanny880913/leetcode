#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int find(int i, vector<int> &root)
{
    if (root[i] != i)
    {
        root[i] = find(root[i], root);
    }
    return root[i];
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    int group_num = n;
    int con_size = connections.size();
    vector<int> root(n);

    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < con_size; i++)
    {
        int root_a = find(connections[i][0],root), root_b = find(connections[i][1],root);
        if(root_a != root_b){
            group_num--;
            root[root_a]=root_b;
        }
    }
    return group_num-1;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    int n = 4;
    makeConnected(n, connections);
    return 0;
}