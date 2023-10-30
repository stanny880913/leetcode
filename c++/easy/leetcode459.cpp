#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s)
{
  int n = s.length();
  for (int i = 1; i <= n / 2; i++)
  {
    if (n % i == 0)
    {
      string temp = "";
      string subString = s.substr(0, i);
      for (int j = 0; j < n / i; j++)
      {
        temp += subString;
      }
      if(temp == s)
        return true;
    }
  }
  return false;
}

int main()
{
  string s = "abcabc";
  repeatedSubstringPattern(s);
  return 0;
}