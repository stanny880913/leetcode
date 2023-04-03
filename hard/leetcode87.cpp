    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>

    using namespace std;
    unordered_map<string, bool> map;
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
        {
            return true;
        }

        if (s1.length() != s2.length())
        {
            return false;
        }

        string sort1 = s1, sort2 = s2;
        sort(sort1.begin(), sort1.end());
        sort(sort2.begin(), sort2.end());
        if (sort1 != sort2)
        {
            return false;
        }

        int s1_size = s1.length();
        string key = s1 + "" + s2;
        bool flag = false;

        if (map.find(key) != map.end())
        {
            return map[key];
        }

        for (int i = 1; i < s1_size; i++)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1_size - i), s2.substr(i, s1_size - i)))
            {
                flag = true;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s1_size - i, i)) && isScramble(s1.substr(i, s1_size - i), s2.substr(0, s1_size - i)))
            {
                flag = true;
                return true;
            }
            map[key] = flag;
        }
        return false;
    }
    int main()
    {
        string s1 = "eebaacbcbcadaaedceaaacadccd";
        string s2 = "eadcaacabaddaceacbceaabeccd";
        isScramble(s1, s2);
        return 0;
    }