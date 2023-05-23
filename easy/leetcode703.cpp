#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (auto num : nums)
            pq.push(num);
    }

    int add(int val)
    {
        pq.push(val);

        while (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    vector<int> nums{4, 5, 8, 2};
    int k = 3;
    KthLargest *kthLargest = new KthLargest(k, nums);
    kthLargest->add(3);  // return 4
    kthLargest->add(5);  // return 5
    kthLargest->add(10); // return 5
    kthLargest->add(9);  // return 8
    kthLargest->add(4);  // return 8
    return 0;
}