#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

typedef unsigned long long ull;

struct bigint {
  char buffer[210];
  int size = 0;
  bigint() = default;
  bigint(char value);
  bigint operator+(const bigint& a);
  bigint operator+(const char x);
  friend ostream& operator>>(ostream& os, const bigint& bi);
};
bigint::bigint(char value)
{
  string s = to_string(value);
  size = s.size();
  for(int i=0;i<s.size();i++)
    buffer[i] = s[i] - '0';
}

bigint bigint::operator+(const char x)
{
  bigint n, r(x);
  return n + r;
}

bigint bigint::operator+(const bigint& a)
{
  bigint n;
  memset(n.buffer, 0, 100);
  bool carry = false;
  int size = 0;
  size = max({this->size, a.size}) + 1;
  for(int i=0;i<size;i++)
  {
    char val = (i < this->size ? this->buffer[i] : 0) + (i < a.size ? a.buffer[i] : 0) + (carry ? 1 : 0);
    if(carry == false && i == size - 1){
      size--;
      break;
    }
    if(val >= 10){
      carry = true;
      val -= 10;
    }else carry = false;
    n.buffer[i] = val;
  }
  n.size = size;
  return n;
}

ostream& operator<<(ostream& os, const bigint& bi)
{
  for(int i = bi.size-1; i >= 0; i--)
    os << (char)(bi.buffer[i] + '0');
  return os;
}

bigint _f[MAX];

bigint fib(int i)
{
  if(i<=2) return (char)1;
  if(_f[i].size == 0) _f[i] = fib(i-1) + fib(i-2);
  return _f[i];
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int i;
  while(cin >> i)
    cout << fib(i+1) << '\n';

  return 0;
}
