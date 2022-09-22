#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int y;
    cin >> y;
    cout << "Case " << (i+1) << ": ";
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
      cout << "a leap year\n";
      continue;
    }
    cout << "a normal year\n";
  }
  return 0;
}
