#include "header/ListNode.h"
#include <algorithm>
#include <vector>

using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current)
    {
        ListNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    int carry = 0;
    ListNode *ans = new ListNode();
    ListNode *curr = ans;

    while (l1 || l2 || carry != 0)
    {
        int total_sum = carry;
        if (l1)
        {
            total_sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            total_sum += l2->val;
            l2 = l2->next;
        }

        carry = total_sum / 10;
        ListNode *node = new ListNode(total_sum % 10);
        curr->next = node;
        curr = curr->next;
    }

    // ListNode *temp = ans;
    // ans = ans->next;
    // delete temp;

    // ans = reverseList(ans);
    ans = reverseList(ans->next);
    return ans;
}

int main()
{
    vector<int> l1 = {5};
    vector<int> l2 = {5};
    addTwoNumbers(buildList(l1, 0), buildList(l2, 0));
    return 0;
}