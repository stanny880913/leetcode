#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    string ans = "";
    string temp = "";

    for (int i = 0; i <= path.length(); i++)
    {
        if (i < path.length() && path[i] != '/')
        {
            temp.push_back(path[i]);
            continue;
        }
        else
        {
            if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (!temp.empty() && temp != ".")
            {
                st.push(temp);
            }
            temp = "";
        }
    }

    if (st.empty())
    {
        return ans += '/';
    }
    else
    {
        while (!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        return ans;
    }
}

int main()
{
    string path = "/a//b////c/d//././/..";
    simplifyPath(path);
    return 0;
}