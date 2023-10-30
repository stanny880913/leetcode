#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++)
  {
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;

    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == target)
        return true;
    }
  }
  return false;
}

int main()
{
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  searchMatrix(matrix, target);
  return 0;
}