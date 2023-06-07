#include <vector>
#include <iostream>

using namespace std;

int minFlips(int a, int b, int c)
{
    int ans = 0;

    while ((a | b) != c)
    {
        if (c & 1 == 1)
        {
            if ((a & 1) == 0 && (b & 1) == 0)
                ans++;
        }
        else
            ans += (a & 1) + (b & 1);

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return ans;
}

int main()
{
    int a = 2, b = 6, c = 5;
    minFlips(a, b, c);
    return 0;
}