#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  cout << ((n % 3 == 0) ? (n / 3) : static_cast<int>(floor(n/3)+1));
  return 0;
}
