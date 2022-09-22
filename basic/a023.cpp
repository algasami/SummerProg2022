#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int y;
  cin >> y;
  if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
  {
    cout << "a leap year";
    return 0;
  }
  cout << "a normal year";
  return 0;
}
