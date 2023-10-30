#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tribonacci(int n)
{
    int n0 = 0, n1 = 1, n2 = 1, ans;
    if (n < 2)
        return n;
    if (n == 2)
        return 1;
    for (int i = 3; i <= n; i++)
    {
        ans = n0 + n1 + n2;
        n0 = n1;
        n1 = n2;
        n2 = ans;
    }
    return ans;
}


int main()
{
    int ans = tribonacci(10);
    cout << ans;
    return 0;
}