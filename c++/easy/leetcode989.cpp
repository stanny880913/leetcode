#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
    vector<int> ans;
    int num_size = num.size() - 1, carry = 0;

    while (k > 0 || num_size >= 0 || carry > 0)
    {
        int sum = carry;
        int temp = k % 10; //取餘數
        if (k > 0)
        {
            sum += temp;
            k /= 10;
        }
        if (num_size >= 0)
        {
            sum += num[num_size];
            num_size--;
        }
        carry = sum / 10;
        ans.push_back(sum % 10);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> num = {2, 7, 4};
    int k = 181;
    addToArrayForm(num, k);
    return 0;
}