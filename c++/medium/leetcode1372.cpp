#include <iostream>
#include <vector>
#include <algorithm>
#include "header/TreeNode.h"

using namespace std;

void dfs(TreeNode *node, bool go_left, int curr_steps, int &ans)
{
    if (node == nullptr)
        return;

    ans = max(ans, curr_steps);

    if (go_left)
    {
        dfs(node->left, false, curr_steps + 1, ans);
        dfs(node->right, true, 1, ans);
    }
    else
    {
        dfs(node->left, false, 1, ans);
        dfs(node->right, true, curr_steps + 1, ans);
    }
}

int longestZigZag(TreeNode *root)
{
    int ans = 0;
    int curr_steps = 0;
    dfs(root, false, curr_steps, ans);
    dfs(root, true, curr_steps, ans);
    return ans;
}

int main()
{
    vector<int> root = {
        1,
        NULL,
        1,
        NULL,
        NULL,
        1,
        1,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        1,
        1,
    };
    // int index = 0;
    buildTree(root, 0);
    longestZigZag(buildTree(root, 0));
    return 0;
}