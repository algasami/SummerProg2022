#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (true) {
    unsigned int a, b, c;
    if (!(cin >> a >> b >> c))
      break;
    if (a > b + c || (c > a && a > b && a + b > c) ||
        (b > a && a > c && a + c > b))
      cout << 'A';
    else if (b > a + c || (c > b && b > a && a + b > c) ||
             (a > b && b > c && b + c > a))
      cout << 'B';
    else
      cout << 'C';
    cout << '\n';
  }
  return 0;
}