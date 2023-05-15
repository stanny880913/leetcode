#include <iostream>
#include <algorithm>
#include "header/ListNode.h"

using namespace std;

ListNode *swapNodes(ListNode *head, int k)
{
    int len = 0;
    ListNode *curr_node = head, *start = head, *end = head;

    if (k <= 0 || !head)
        return head;

    while (curr_node)
    {
        len++;
        curr_node = curr_node->next;
    }

    for (int i = 0; i < k-1; i++)
        start = start->next;
    for (int j = 0; j < len - k; j++)
        end = end->next;
    
    swap(start->val,end->val);
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    buildList(arr, 0);
    swapNodes(buildList(arr, 0), k);
    return 0;
}