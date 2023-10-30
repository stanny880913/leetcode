#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLastWord(string s)
{
  int ans = 0;
  int n = s.size() - 1;
  for (int i = n; i >= 0; i--)
  {
    if (ans == 0 && s[i] == ' ')
      continue;
    else if (ans != 0 && s[i] == ' ')
      break;
    else
      ans++;
  }
  return ans;
}

int main()
{
  string s = "   fly me   to   the moon  ";
  lengthOfLastWord(s);
  return 0;
}