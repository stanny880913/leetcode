#include <iostream>
#include <algorithm>
#include "header/TreeNode.h"

using namespace std;

// void dfs(TreeNode *node, vector<int> &node_val)
// {
//     if (node == NULL)
//     {
//         return;
//     }

//     node_val.push_back(node->val);
//     dfs(node->left, node_val);
//     dfs(node->right, node_val);
// }

void inorder(TreeNode *node, vector<int> &node_val)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left,node_val);
    // Store the nodes in the list.
    node_val.push_back(node->val);
    inorder(node->right,node_val);
}

int getMinimumDifference(TreeNode *root)
{
    vector<int> val;
    // dfs(root, val);
    // sort(val.begin(), val.end());
    inorder(root, val);
    
    int ans = INT32_MAX;

    for (int i = 1; i < val.size(); i++)
        ans = min(ans, val[i] - val[i - 1]);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    getMinimumDifference(root);
    return 0;
}
