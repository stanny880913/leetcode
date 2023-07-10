#include <iostream>
#include <algorithm>
#include "header/TreeNode.h"

using namespace std;

int dfs(TreeNode *root)
{
    if (root == NULL)
        return 0;
    else if (!root->left)
        return dfs(root->right) + 1;
    else if (!root->right)
        return dfs(root->left) + 1;

    return 1 + min(dfs(root->left), dfs(root->right));
}

int minDepth(TreeNode *root)
{
    return dfs(root);
}

int main()
{
    vector<int> root = {1, 2, 3, 4, 5};
    buildTree(root, 0);
    minDepth(buildTree(root, 0));
    return 0;
}
