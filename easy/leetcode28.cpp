#include <iostream>
#include <vector>
using namespace std;
int strStr(string haystack, string needle)
{
    for (int i = 0; i < haystack.length(); i++)
    {
        string subHayStack = haystack.substr(i, needle.length());
        if (subHayStack == needle)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    strStr(haystack, needle);
    return 0;
}