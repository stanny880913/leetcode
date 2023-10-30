#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "header/TreeNode.h"

using namespace std;

TreeNode *buildNewTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &map, int &rootIdx, int start, int end)
{
    if (start > end)
        return NULL;

    int map_key = map[postorder[rootIdx]];
    TreeNode *node = new TreeNode(postorder[rootIdx]); //root = postorder last index
    rootIdx--;

    node->right = buildNewTree(inorder, postorder, map, rootIdx, map_key + 1, end);
    node->left = buildNewTree(inorder, postorder, map, rootIdx, start, map_key - 1);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int rootIdx = postorder.size() - 1;
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;

    return buildNewTree(inorder, postorder, map, rootIdx, 0, inorder.size() - 1);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3}; // last index is root
    buildTree(inorder,postorder);
    return 0;
}