#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int> &fruits)
{
    // vector<int> buckets;
    // int count = 0;
    // int ans = 0;

    // if (fruits.size() <= 2)
    // {
    //     return fruits.size();
    // }

    // for (int i = 0; i < fruits.size() - 2; i++)
    // {
    //     if (buckets.empty())
    //     {
    //         if (fruits[i] == fruits[i + 1])
    //         {
    //             buckets.push_back(fruits[i]);
    //             count += 2;
    //         }
    //         else
    //         {
    //             buckets.push_back(fruits[i]);
    //             count++;
    //             buckets.push_back(fruits[i + 1]);
    //             count++;
    //         }
    //     }
    //     if (buckets.size() < 2 && buckets[0] != fruits[i + 2])
    //     {
    //         buckets.push_back(fruits[i + 2]);
    //     }
    //     if (fruits[i + 2] != buckets[0] && fruits[i + 2] != buckets[1])
    //     {
    //         buckets.erase(buckets.begin());
    //         buckets.push_back(fruits[i + 2]);
    //         ans = max(ans, count);
    //         if (fruits[i] == fruits[i + 1])
    //         {
    //             count = 3;
    //         }
    //         else
    //         {
    //             count = 2;
    //         }
    //     }
    //     else if (fruits[i + 2] == buckets[0] || fruits[i + 2] == buckets[1])
    //     {

    //         if (fruits[i] == fruits[i + 1] == fruits[i + 2])
    //         {
    //             count = 4;
    //         }
    //         else
    //         {
    //             count++;
    //         }
    //     }
    //     ans = max(ans, count);
    // }
    // return ans;
    vector<int> bucket;
    int ans = 0, count = 0;
    if (fruits.size() == 1)
    {
        return 1;
    }

    for (int i = 0; i < fruits.size() - 1; i++)
    {
        bucket.push_back(fruits[i]);
        if (fruits[i] == fruits[i + 1])
        {
            count += 1;
            ans = max(count, ans);
            bucket.erase(bucket.begin());
            continue;
        }
        for (int j = i + 1; j < fruits.size(); j++)
        {
            int bucketLen = bucket.size();
            int flag = 0; // 判斷fruits是否在bucket裏面(1==true)
            for (int b = 0; b < bucketLen; b++)
            {
                if (bucket[b] == fruits[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (bucketLen < 2 && flag == 0)
            {
                bucket.push_back(fruits[j]);
            }
            if (flag == 0 && bucketLen == 2)
            {
                count = 0;
                break;
            }

            count++;
            ans = max(ans, count);
            if (j == fruits.size() - 1)
                return ans + 1;
        }
        bucket.clear();
    }
    return ans + 1;
};

int main()
{
    vector<int> fruits = {4, 1, 1, 1, 3, 1, 7, 5};
    totalFruit(fruits);
    return 0;
}