#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    // ListNode *now = head;
    // unordered_map<ListNode *, int> addressTable;

    // while (now)
    // {
    //     if (addressTable.find(now) == addressTable.end()) // 表示now不存在addressTable中
    //     {
    //         addressTable[now] = now->val;
    //         now = now->next;
    //     }
    //     else
    //     {
    //         return now;
    //     }
    // }
    // return NULL;

    // fast and slow
    ListNode *FastNode = head;
    ListNode *SlowNode = head;

    while (true)
    {
        if (FastNode != NULL && FastNode->next != NULL)
        {
            SlowNode = SlowNode->next;
            FastNode = FastNode->next->next;
        }
        else
            return NULL;
        if (SlowNode == FastNode)
            break;
    }
    while (SlowNode != head)
    {
        SlowNode = SlowNode->next;
        head = head->next;
    }
    return head;
}

int main()
{
    // initialize a cycle list
    vector<int> values = {3, 2, 0, -4};
    ListNode *head = new ListNode(values[0]);
    ListNode *cur = head;
    for (int i = 1; i < values.size(); i++)
    {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    cur->next = head->next;
    detectCycle(head);
    return 0;
}