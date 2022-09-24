#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int r = n / 12, l = n % 12;
  cout << (r * 50) + (l * 5);
  return 0;
}