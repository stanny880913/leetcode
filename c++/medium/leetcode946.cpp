#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int pop_curr = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
        st.push(pushed[i]);
        while(!st.empty() && popped[pop_curr] == st.top())
        {
            st.pop();
            pop_curr++;
        }
    }
    return st.empty();
}
int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    validateStackSequences(pushed, popped);
    return 0;
}