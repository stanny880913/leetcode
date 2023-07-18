#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
private:
    int capacity;
    unordered_map<int, list<std::pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }
        auto it = cache[key];
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            auto it = cache[key];
            lru.erase(it);
            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
        else
        {
            if (lru.size() >= capacity)
            {
                int lastKey = lru.back().first;
                lru.pop_back();
                cache.erase(lastKey);
            }

            lru.push_front({key, value});
            cache[key] = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
