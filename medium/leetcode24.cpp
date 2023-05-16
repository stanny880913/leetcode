#include <iostream>
#include <algorithm>
#include "header/ListNode.h"

using namespace std;

ListNode *swapPairs(ListNode *head)
{
    // Iteration
    if (!head || !head->next)
        return head;

    ListNode *pre = head, *curr_node = head->next, *ans = head->next;

    while (1)
    {
        pre->next = curr_node->next;
        curr_node->next = pre;
        ListNode *temp = pre->next;
        curr_node = (temp == NULL) ? NULL : temp->next;
        if (curr_node == NULL)
            break;
        pre->next = curr_node;
        pre = temp;
    }
    return ans;

    // recursive
    // if (!head || !head->next)
    //     return head;
    // ListNode *ans = head->next;
    // head->next = swapPairs(head->next->next);
    // ans->next = head;
    // return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    swapPairs(buildList(arr, 0));
    return 0;
}