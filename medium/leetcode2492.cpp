#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

static bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

int minScore(int n, vector<vector<int>> &roads)
{   
    int road_size = roads.size();
    for(int i=0;i<roads.size();i++){
        sort(roads[i][0],roads[i][1]);
    }
    sort(roads.begin(), roads.end(), sortcol);

    int min = INT16_MAX;
    

    set<int> val;
    val.insert(roads[0][0]);

    for (int i = 0; i < road_size; i++)
    {
        if (val.find(roads[i][0]) != val.end())
        {
            val.insert(roads[i][1]);
            min = roads[i][2]<min?roads[i][2]:min;
        }
    }
    return min;
}

int main()
{
    vector<vector<int>> roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    int n = 4;
    minScore(n, roads);
    return 0;
}