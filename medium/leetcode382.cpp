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

class Solution
{
public:
    vector<int> randomNodes;
    Solution(ListNode *head)
    {
        ListNode *now = head;
        while (now != NULL)
        {
            
            randomNodes.push_back(now->val);

            now = now->next;
        }
    }

    int getRandom()
    {
        int randomSize = randomNodes.size();
        int randomVal = randomNodes[rand() % randomSize];
        return randomVal;
    }
};

int main()
{
    // initialize a cycle list
    vector<int> values = {1, 2, 3};
    ListNode *head = new ListNode(values[0]);
    ListNode *cur = head;
    for (int i = 1; i < values.size(); i++)
    {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    Solution *obj = new Solution(head);
    int num = obj->getRandom();
    cout << num;
    return 0;
}