#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
string removeStars(string s)
{
    // stack
    // stack<char> sta;

    // for (int i = 0; i < s.length(); i++)
    // {
    //     char current_char = s[i];
    //     if (current_char == '*')
    //     {
    //         sta.pop();
    //     }
    //     else
    //     {
    //         sta.push(current_char);
    //     }
    // }
    // string ans = "";

    // while (!sta.empty())
    // {
    //     ans += sta.top();
    //     sta.pop();
    // }
    // reverse(ans.begin(),ans.end());
    // return ans;
    // string Simulation
    string ans="";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '*'){
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{
    string s = "leet**cod*e";
    removeStars(s);
    return 0;
}