#include <set>
#include <vector>
#include <iostream>
using namespace std;

class SmallestInfiniteSet
{
public:
    set<int> set;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            set.insert(i);
        }
    }

    int popSmallest()
    {
        auto ans = *set.begin();
        set.erase(set.begin());
        return ans;
    }

    void addBack(int num)
    {
        set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */