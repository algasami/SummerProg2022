#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h, m;
  bool flag = false;
  cin >> h >> m;
  if (h < 17 && h > 7)
    flag = true;
  else if (h == 7 && m > 30)
    flag = true;
  cout << (flag ? "At School" : "Off School");
  return 0;
}
