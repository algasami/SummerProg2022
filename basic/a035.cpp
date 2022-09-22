#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a,b,c;
  cin >> a >> b >> c;
  int s = (a+b+c)/2;
  cout << (s*(s-a)*(s-b)*(s-c));

  return 0;
}
