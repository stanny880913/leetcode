#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

string convert(string s, int numRows)
{
    string ans = "";
    if (numRows <= 1)
    {
        return s;
    }

    for (int i = 0; i < numRows; i++)
    {
        int nexthead = (numRows - 1) * 2;
        for (int j = i; j < s.size(); j += nexthead)
        {
            ans += s[j];
            int nextword = j + nexthead - 2 * i;
            if (i != 0 && i < numRows - 1 && nextword < s.size())
            {
                ans += s[nextword];
            }
        }
    }
    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;
    convert(s, numRows);
    return 0;
}