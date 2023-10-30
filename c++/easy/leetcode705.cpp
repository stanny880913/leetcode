#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet
{
public:
    vector<bool> ans;

    MyHashSet()
    {
        ans.resize(1e5 + 5, false);
    }

    void add(int key)
    {
        ans[key] = true;
    }

    void remove(int key)
    {
        ans[key] = false;
    }

    bool contains(int key)
    {
        return ans[key];
    }
};

int main()
{
    int key;
    MyHashSet *obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    obj->contains(1);
    return 0;
}