#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    string ans = "";
    int x = word1.length(), y = word2.length(), max_len = max(x, y);
    for (int i = 0; i < max_len; i++)
    {

        if (x != 0)
        {
            ans += word1[i];
            x--;
        }
        if (y != 0)
        {
            ans += word2[i];
            y--;
        }
    }
    return ans;
}
int main()
{
    string word1 = "ab";
    string word2 = "pqrs";
    mergeAlternately(word1, word2);
    return 0;
}