#include <iostream>
#include <vector>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];

    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];

    for (int i = 2; i < coordinates.size(); i++)
    {
        int dx = coordinates[i][0], dy = coordinates[i][1];
        if ((dy - y1) * (dx - x2) != (dy - y2) * (dx - x1))
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    checkStraightLine(coordinates);
    return 0;
}