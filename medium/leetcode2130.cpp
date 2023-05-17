#include <iostream>
#include <algorithm>
#include "header/ListNode.h"

using namespace std;

int pairSum(ListNode *head)
{   
    ListNode *curr_node = head;
    vector<int> list_val;

    while (curr_node)
    {
        list_val.push_back(curr_node->val);
        curr_node = curr_node->next;
    }
    int start = 0, end = list_val.size() - 1, ans = 0;

    while (1)
    {
        ans = max(ans, list_val[start] + list_val[end]);
        start++;
        end--;
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 4, 2, 1};
    pairSum(buildList(arr, 0));
    return 0;
}