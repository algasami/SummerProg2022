#include<bits/stdc++.h>
using namespace std;

inline void clean(stack<char>& stk)
{
  while(stk.empty()==false)
  {
    char c = stk.top();
    cout << (char)(c + 2);
    stk.pop();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string s;
  getline(cin,s);
  stack<char> stk;
  for(int i=0;i<s.size();i++)
  {
    char c = s[i];
    if(c == ' ')
    {
      clean(stk);
      cout << (char)(' ' + 2);
      continue;
    }
    stk.push(c);
  }
  clean(stk);
  return 0;
}
