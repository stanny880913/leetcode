int totalMoney(int n)
{
  int full_week = n / 7;
  int not_full_week = n % 7;

  int ans = ((full_week * (full_week - 1)) / 2 * 7);
  ans += full_week * 28;
  ans += ((not_full_week * (not_full_week + 1)) / 2) + (full_week * not_full_week);
  return ans;
}

int main()
{
  int n = 20;
  totalMoney(n);
  return 0;
}