#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graphs, vector<int> &visited, int node)
{
    // 2 = conflict
    if (visited[node] == 2)
        return false;
    // 1 = visited
    if (visited[node] == 1)
        return true;

    visited[node] = 2;

    for (auto graph : graphs[node])
    {
        if (!dfs(graphs, visited, graph))
            return false;
    }
    visited[node] = 1;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graphs(numCourses);
    vector<int> visited(numCourses);
    for (auto prerequisite : prerequisites)
        graphs[prerequisite[1]].push_back(prerequisite[0]);

    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(graphs, visited, i))
            return false;
    }
    return true;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    canFinish(numCourses, prerequisites);
    return 0;
}