#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestAltitude(vector<int> &gain)
{
    int temp=0,ans = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        temp += gain[i];
        ans = max(ans,temp); 
    }
    return ans;
}

int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};
    largestAltitude(gain);
    return 0;
}