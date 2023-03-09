
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

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

void Inorder(TreeNode *node, vector<int>& arr_tree)
{
    if (node == NULL)
    {
        return;
    }
    Inorder(node->left, arr_tree);
    arr_tree.push_back(node->val);
    Inorder(node->right, arr_tree);
}

int minDiffInBST(TreeNode *root)
{
    vector<int> arr_ans;
    int ans = INT16_MAX;
    Inorder(root, arr_ans);

    for (int i = 1; i < arr_ans.size(); i++)
    {   
        int a = arr_ans[i-1];
        ans = min(ans, arr_ans[i] - arr_ans[i-1]);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->right = new TreeNode(2236);
    root->right->left = new TreeNode(1277);
    root->right->left->left = new TreeNode(519);
    root->right->right = new TreeNode(2776);
    minDiffInBST(root);
    return 0;
}