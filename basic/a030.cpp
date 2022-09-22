#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, big=0;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int count;
    cin >> count;
    if(count > big) big = count;
  }
  cout << big;
  return 0;
}
