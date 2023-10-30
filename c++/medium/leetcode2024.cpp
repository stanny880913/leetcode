#include <string>
#include <map>
#include <algorithm>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k)
{
    int l = 0, r = 0, n = answerKey.size();
    int ans = 0, maxCount = 0;
    map<char, int> count;

    while (r < n)
    {
        count[answerKey[r]]++;
        maxCount = max(maxCount, count[answerKey[r]]);
        if ((r - l + 1) - maxCount > k)
        {
            count[answerKey[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    int k = 1;
    string answerKey = "TFFT";
    maxConsecutiveAnswers(answerKey, k);
    return 0;
}