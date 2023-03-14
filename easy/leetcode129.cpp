#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int ans)
{
    int a = root->val;
    if (root == NULL)
    {
        return 0;
    }
    ans = ans * 10 + root->val;

    if (root->left == NULL && root->right == NULL)
    {
        return ans;
    }
    int left_Subtree =  dfs(root->left, ans);
    int right_Subtree = dfs(root->right, ans);
    return left_Subtree + right_Subtree;
}

int sumNumbers(TreeNode *root)
{
    return dfs(root, 0);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->right = new TreeNode(0);
    root->left = new TreeNode(9);
    root->left->right = new TreeNode(1);
    root->left->left = new TreeNode(5);
    sumNumbers(root);
}