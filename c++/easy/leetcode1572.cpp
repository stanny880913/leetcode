#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>> &mat)
{
    int ans = 0, n = mat.size();
    for (int i = 0; i < mat.size(); i++)
    {
        ans += mat[i][i];

        if (i != n - i - 1)
            ans += mat[i][n - i - 1];
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    diagonalSum(mat);
    return 0;
}