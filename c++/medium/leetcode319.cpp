#include <iostream>
#include <cmath>

using namespace std;

int bulbSwitch(int n)
{
    // int count = 0;
    // for (int i = 1; i * i <= n; i++)
    // {
    //     count++;
    // }
    // return count;
    return sqrt(n);
}

int main()
{
    int n = 3;
    bulbSwitch(n);
    return 0;
}

// n = 5
// first = 0 0 0 0 0
// r1 = 1 1 1 1 1   5
// r2 = 1 0 1 0 1   3
// r3 = 1 0 0 0 1   2
// r4 = 1 0 0 1 1   3
// r5 = 1 0 0 1 0   2
