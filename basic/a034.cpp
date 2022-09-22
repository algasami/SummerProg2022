#include<bits/stdc++.h>
using namespace std;

typedef long long int uli;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  uli a,b,count = 0;
  cin >> a >> b;
  uli n = b - a + 1;
  if(a==b)
  {
    if(a%2 == 0)
    {
      cout << 1;
    }else
    {
      cout << 0;
    }
    return 0;
  }
  if((n&1) == 0)
  {
    count = n/2;
  }else
  {
    if((a&1) == 1 || (b&1) == 1)
    {
      count = n - (n/2 + 1);
    }else {
      count = n - (n/2);
    }
  }
  cout << count;
  return 0;
}
