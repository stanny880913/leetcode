#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(int n, vector<int> &b, long long int hrs)
{
    long long int sum = 0;
    for (int i = 0; i < b.size(); i++)
    {
        sum += b[i];
        if (sum >= hrs)
            sum -= hrs, n--;
        if (n == 0)
            return true;
    }
    return false;
}

long long maxRunTime(int n, vector<int> &b)
{
    long long int start = 1, end = 0;
    for (int i = 0; i < b.size(); i++)
        end += b[i];
    end /= n;

    sort(b.begin(), b.end());
    while (start < end)
    {
        long long int mid = start + (end - start + 1) / 2;
        if (possible(n, b, mid))
            start = mid;
        else
            end = mid - 1;
    }
    return start;
}

int main()
{
    vector<int> batteries = {3, 3, 3};
    int n = 2;
    maxRunTime(batteries, n);
    return 0;
}