public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[i] + nums[j] == target)
                    return new int[] { i, j };
            }
        }
        return new int[] { };
    }

    public static void Main()
    {
        int[] nums = { 2, 7, 11, 5 };
        int target = 9;
        Solution solution = new Solution();
        int[] ans = solution.TwoSum(nums, target);

        // 這裡要使用迴圈或其他方式遍歷 ans 陣列並輸出每個元素
        foreach (int num in ans)
        {
            Console.WriteLine(num);
        }
    }
}
