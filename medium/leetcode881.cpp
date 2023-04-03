#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    int start = 0, end = people.size() - 1, count = 0;
    sort(people.begin(), people.end());

    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
        {
            start++;
            end--;
        }
        end--;
        count++;
    }
    return count;
}

int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 10;
    numRescueBoats(people, limit);
    return 0;
}