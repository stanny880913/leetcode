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

// Recursive Code
// bool isMirror(TreeNode *leftFrontNode, TreeNode *rightFrontNode)
// {
//     if (leftFrontNode == NULL && rightFrontNode == NULL)
//     {
//         return true;
//     }
//     if (leftFrontNode == NULL || rightFrontNode == NULL || leftFrontNode->val != rightFrontNode->val)
//     {
//         return false;
//     }
//     return isMirror(leftFrontNode->left, rightFrontNode->right) && isMirror(leftFrontNode->right, rightFrontNode->left);
// }
// bool isSymmetric(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     return isMirror(root->left, root->right);
// }

// Non-Recursive Code
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty())
    {
        TreeNode *leftFrontNode = q.front();
        q.pop();
        TreeNode *rightFrontNode = q.front();
        q.pop();

        if (leftFrontNode == NULL && rightFrontNode == NULL)
            continue;
        if (leftFrontNode == NULL || rightFrontNode == NULL || leftFrontNode->val != rightFrontNode->val)
            return false;
        q.push(leftFrontNode->left);
        q.push(rightFrontNode->right);
        q.push(leftFrontNode->right);
        q.push(rightFrontNode->left);
    }
    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(3);
    root->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    isSymmetric(root);
}