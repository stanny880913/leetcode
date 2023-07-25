#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "" ;

    sort(strs.begin(), strs.end());

    string x = strs[0];
    string y = strs[strs.size() - 1];
    string ans = "";

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == y[i])
            ans += x[i];
        else
            break;
    }
    return ans;
}

int main()
{
    vector<string> strs = {{""}};
    longestCommonPrefix(strs);
    return 0;
}