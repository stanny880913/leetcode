#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    // return ans = pow(x, n);
    if (n == 0)
        return 1;

    else if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }

    if (n % 2 == 0)
        return myPow(x * x, n / 2);
    else
        return x * myPow(x, n - 1);
}

int main()
{
    double x = 2.00000;
    int n = 2147483647;
    myPow(x, n);
    return 0;
}