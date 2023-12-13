public class Solution
{
    public int NumSpecial(int[][] mat)
    {
        int result = 0;
        for (int i = 0; i < mat.Length; i++)
        {
            for (int j = 0; j < mat[i].Length; j++)
            {
                if (mat[i][j] == 1)
                {
                    int sumx = 0;
                    int sumy = 0;
                    for (int m = 0; m < mat[i].Length; m++)
                    {
                        sumx += mat[i][m];
                    }
                    for (int k = 0; k < mat.Length; k++)
                    {
                        sumy += mat[k][j];
                    }
                    if (sumx == 1 && sumy == 1)
                    {
                        result++;
                    }
                }
            }
        }
        return result;
    }
    public static void Main()
    {
        int[][] mat = { new int[] { 1, 0, 0 }, new int[] { 0, 0, 1 }, new int[] { 1, 0, 0 } };
        // 創建 Solution 類別的實例
        Solution solution = new Solution();
        // 呼叫 NumSpecial 方法
        int specialCount = solution.NumSpecial(mat);
        // 顯示結果
        Console.WriteLine(specialCount);
    }
}

