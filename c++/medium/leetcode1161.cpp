#include <iostream>
#include <queue>
#include "header/TreeNode.h"

using namespace std;

int maxLevelSum(TreeNode *root)
{
    int ans, max_Sum = INT16_MIN, level = 1;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int current_level_sum = 0;
        for (int i = q.size(); i > 0; i--)
        {
            TreeNode *node = q.front();
            current_level_sum += node->val;
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        if(max_Sum < current_level_sum)
        {
            max_Sum = current_level_sum;
            ans = level;
        }
        level++;
    }
    return ans;
}

int main()
{
    vector<int> root = {1, 7, 0, 7, -8, NULL, NULL};
    // int index = 0;
    buildTree(root, 0);
    maxLevelSum(buildTree(root, 0));
    return 0;
}