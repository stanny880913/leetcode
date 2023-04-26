#include <iostream>

using namespace std;

int addDigits(int num)
{
    int ans = 0;
    if (num <= 9)
        return num;

    while (num != 0)
    {
        ans = num / 10 + num % 10;
        num = ans;

        if (num <= 9)
            break;
    }
    return ans;
}

int main()
{
    int num = 10;
    addDigits(num);
    return 0;
}