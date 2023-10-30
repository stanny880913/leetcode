#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

double average(vector<int> &salary)
{
    // TimeComplexity =  nlogn
    //  double ans = 0;
    //  sort(salary.begin(), salary.end());
    //  ans = accumulate(salary.begin() + 1, salary.end() - 1,0);
    //  return ans / (salary.size() - 2);

    // TimeComplexity = n
    int min = INT32_MAX, max = 0;
    double ans = 0;
    for (int i = 0; i < salary.size(); i++)
    {
        if (salary[i] < min)
            min = salary[i];
        if (salary[i] > max)
            max = salary[i];
        ans += salary[i];
    }
    return (ans - min - max) / (salary.size() - 2);
}

int main()
{
    vector<int> salary = {4000, 3000, 1000, 2000};
    average(salary);
    return 0;
}