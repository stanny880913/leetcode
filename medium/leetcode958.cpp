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

bool isCompleteTree(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    queue<TreeNode *> q; // 用於儲存node的queue，非int
    bool is_null = false;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *cur_node = q.front();
        q.pop();

        if (cur_node == NULL)
        {
            is_null = true;
            continue;
        }

        if (is_null == true)
        {
            return false;
        }

        q.push(cur_node->left);
        q.push(cur_node->right);
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    // root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    isCompleteTree(root);
}