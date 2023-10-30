#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSimilarStr(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            cnt++;
    }
    bool isSimilar = (cnt == 2 || cnt == 0) ? true : false;
    return isSimilar;
}

void dfs(int i, vector<string> &strs, vector<bool> &visited, int n)
{
    visited[i] = true;
    for (int j = 0; j < n; j++)
    {
        if (visited[j])
            continue;

        if (isSimilarStr(strs[i], strs[j]))
            dfs(j, strs, visited, n);
    }
}

int numSimilarGroups(vector<string> &strs)
{
    int ans = 0, n = strs.size();
    vector<bool> visited(strs.size(), false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        ans++;
        dfs(i, strs, visited, n);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"tars", "rats", "arts", "star"};
    numSimilarGroups(strs);
    return 0;
}