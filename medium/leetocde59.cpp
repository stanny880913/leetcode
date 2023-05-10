#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int start = 1, end = n * n;
    int up = 0, down = n - 1, left = 0, right = n - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));

    while (left <= right && up <= down)
    {
        for (int i = left; i <= right; i++)
        {
            ans[up][i] = start++;
        }
        up++;
        for (int i = up; i <= down; i++)
        {

            ans[i][right] = start++;
        }
        right--;
        for (int i = right; i >= left; i--)
        {

            ans[down][i] = start++;
        }
        down--;
        for (int i = down; i >= up; i--)
        {

            ans[i][left] = start++;
        }
        left++;
    }
    return ans;
}

int main()
{
    int n = 3;
    generateMatrix(n);
    return 0;
}