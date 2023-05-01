#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

double average(vector<int> &salary)
{
    double ans = 0;
    sort(salary.begin(), salary.end());
    ans = accumulate(salary.begin() + 1, salary.end() - 1,0);
    return ans / (salary.size() - 2);
}

int main()
{
    vector<int> salary = {4000, 3000, 1000, 2000};
    average(salary);
    return 0;
}