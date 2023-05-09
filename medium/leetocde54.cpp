#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    int start = 0, end = row * col;
    int up = 0, down = row - 1, left = 0, right = col - 1;
    vector<int> ans;

    while (up <= down && left <= right)
    {
        for (int i = left; i <= right && start < end; i++)
        {
            ans.push_back(matrix[up][i]);
            start++;
        }
        up++;
        for (int i = up; i <= down && start < end; i++)
        {
            ans.push_back(matrix[i][right]);
            start++;
        }
        right--;

        for (int i = right; i >= left && start < end; i--)
        {
            ans.push_back(matrix[down][i]);
            start++;
        }
        down--;

        for (int i = down; i >= up && start < end; i--)
        {
            ans.push_back(matrix[i][left]);
            start++;
        }
        left++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{6, 9, 7}};
    spiralOrder(matrix);
    return 0;
}