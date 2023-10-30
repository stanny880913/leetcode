#include <iostream>
#include <vector>
#include <queue>
#include "header/TreeNode.h"

using namespace std;

bool isCompleteTree(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    queue<TreeNode *> bfs_q; // 用於儲存node的queue，非int
    bool is_null = false;
    bfs_q.push(root);

    while (!bfs_q.empty())
    {
        TreeNode *cur_node = bfs_q.front();
        bfs_q.pop();

        if (cur_node == NULL)
        {
            is_null = true;
            continue;
        }

        if (is_null == true)
        {
            return false;
        }

        bfs_q.push(cur_node->left);
        bfs_q.push(cur_node->right);
    }
    return true;
}

int main()
{
    vector<int> tree_arr = {1, 2, 3, 4, 5, NULL, 7};
    int index = 0;
    buildTree(tree_arr, 0);
    isCompleteTree(buildTree(tree_arr, 0));
    return 0;
}