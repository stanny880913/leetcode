#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxVowels(string s, int k)
{
    int ans = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int find_back = i - k;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            cnt++;

        if (i >= k)
        {
            if (s[find_back] == 'a' || s[find_back] == 'e' || s[find_back] == 'i' || s[find_back] == 'o' || s[find_back] == 'u')
                cnt--;
        }
        ans = max(ans, cnt);
    }

    return ans;
}

int main()
{
    string s = "abciiidef";
    int k = 3;
    maxVowels(s, k);
    return 0;
}