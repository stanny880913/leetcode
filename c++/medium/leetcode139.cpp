#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
  unordered_set<string> wordset(wordDict.begin(), wordDict.end());
  vector<bool> dp(s.size() + 1);

  dp[0] = true;

  for (int i = 0; i < dp.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      string test = s.substr(j, i - j);
      if (dp[j] && wordset.count(s.substr(j, i - j)))
      {
        dp[i] = true;
        break;
      }
    }
  }
  return dp.back();
}

int main()
{
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  wordBreak(s, wordDict);
  return 0;
}