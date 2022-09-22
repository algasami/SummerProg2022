#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int a,b, sum = 0;
  cin >> a >> b;
  for(int i=a;i<=b;i++)
  {
    sum += (i&1) ? 0 : i;
  }
  cout << sum;
  //if(a == b)
  //{
    //if((a&1) == 0)
    //{
      //cout << a;
    //}else
    //{
      //cout << 0;
    //}
    //return 0;
  //}
  //a = (a&1) ? (a/2+1) : (a/2);
  //b = (b&1) ? (b/2+1) : (b/2);
  //int result = ((b-a)*(b+a-1));
  //if(result&1){
    //cout << 0;
    //return 0;
  //}
  //cout << result;
  return 0;
}


/**
 *
 * b*(b-1) - a*(a-1)
 * b^2 - b - a^2 + a
 * (b+a)(b-a) - (b - a)
 * (b-a)(b+a-1)
 *
 *
 */
