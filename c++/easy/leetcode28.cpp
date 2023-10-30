#include <iostream>
#include <vector>
#include <gtest/gtest.h>

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

TEST(testCase, test1)
{
    EXPECT_EQ(strStr("sadbutsad", "sad"), 0);
}
TEST(testCase, test2)
{
    EXPECT_EQ(strStr("leetcode", "leeto"), -1);
}

int main(int argc, char **argv)
{
    // string haystack = "sadbutsad";
    // string needle = "sad";
    // strStr(haystack, needle);
    // return 0;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}