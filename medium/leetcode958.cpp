#include <iostream>
#include <vector>
#include <queue>
#include "/home/stannyho/Documents/c++WorkSpace/leetcode/header/TreeNode.h"

using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// TreeNode *buildTree(vector<int> &arr, int index)
// {
//     TreeNode *root = nullptr;
//     if (index < arr.size() && arr[index] != NULL)
//     {
//         root = new TreeNode(arr[index]);
//         root->left = buildTree(arr, 2 * index + 1);
//         root->right = buildTree(arr, 2 * index + 2);
//     }
//     return root;
// }

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
    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(5);
    // root->left->left = new TreeNode(4);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);

    vector<int> tree_arr = {1, 2, 3, 4, 5, NULL, 7};
    int index = 0;
    // buildTree(tree_arr, 0);
    isCompleteTree(buildTree(tree_arr,0));
    return 0;
}