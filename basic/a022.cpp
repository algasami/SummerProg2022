#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int h, m;
  cin >> h >> m;
  if(h > 18 || h < 7 || (h == 7 && m < 30) || (h == 17 && m == 0))
  {
    cout << "Off School";
    return 0;
  }
  cout << "At School";

  return 0;
}
