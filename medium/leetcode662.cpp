#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "header/TreeNode.h"

using namespace std;
int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    unsigned long max_width = 1;
    queue<pair<TreeNode *, unsigned long>> q;

    q.push({root, 1});

    while (!q.empty())
    {
        unsigned long left = q.front().second, right = q.back().second, levelSize = q.size();
        max_width = max(max_width, right - left + 1);

        while(levelSize--)
        {
            unsigned long curr_index = q.front().second;
            TreeNode *curr_node = q.front().first;
            if (curr_node->left)
            {
                q.push({curr_node->left, 2 * curr_index});
            }
            if (curr_node->right)
            {
                q.push({curr_node->right, 2 * curr_index + 1});
            }
            q.pop();
        }
    }
    return max_width;
}
int main()
{
    vector<int> root = {1, 3, 2, 5, NULL, NULL, 9, 6, NULL, 7};
    buildTree(root, 0);
    widthOfBinaryTree(buildTree(root, 0));
    return 0;
}