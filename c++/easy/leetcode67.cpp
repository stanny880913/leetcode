#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string addBinary(string a, string b)
{
    int carry = 0;
    string ans = "";
    int lena = a.size() - 1, lenb = b.size() - 1;

    while (lena >= 0 || lenb >= 0 || carry == 1)
    {
        int sum = 0;
        if (lena >= 0)
        {
            sum += a[lena] - '0';
        }

        if (lenb >= 0)
        {
            sum += b[lenb] - '0';
        }

        sum += carry;

        carry = sum / 2;

        char digit = (sum % 2) + 48;

        ans += digit;

        lena--;
        lenb--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "1010", b = "1011";
    addBinary(a, b);
    return 0;
}