#include<bits/stdc++.h>
using namespace std;

int grade(string& str)
{
  // rule 1
  if(str.size() < 4) return 0;
  for(char c:str)
  {
    if(c == ' ')
    {
      return 0;
    }
  }
  int g = 0;
  int specialCount = 0;
  { // rule 2
    if(str.size() >= 4 && str.size() <= 8) g = 10;
    if(str.size() > 8) g += (str.size()-8)*2 + 10;
  }
  { // rule 3
    for(char c:str)
      if(!isalpha(c) && !isdigit(c)) specialCount++;
    if(specialCount < 3) g -= 6;
  }
  { // rule 4
    bool cap=false,small=false,num=false;
    for(char c:str)
    {
      if(cap&&small&&num) break;
      if(c >= 'A' && c <= 'Z') cap = true;
      if(c >= 'a' && c <= 'z') small = true;
      if(isdigit(c)) num = true;
    }
    g += (int)cap * 2 + (int)small * 2 + (int)num * 2;
  }
  { // rule 5
    g += (specialCount / 5) * 10;
  }
  { // rule 6
    for(int i=0;i<str.size()-1;i++)
    {
      int amode = isalpha(str[i]) ? 0 : (isdigit(str[i]) ? 1 : 2);
      int bmode = isalpha(str[i+1]) ? 0 : (isdigit(str[i+1]) ? 1 : 2);
      if(amode != bmode)
      {
        g += 2;
      }
    }

  }
  return g;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, zeros = 0;
  cin >> n;
  cin.get();
  map<int,vector<string>,greater<int>> grader;
  for(int i=0;i<n;i++)
  {
    string s; getline(cin,s);
    int v = grade(s);
    if(v <= 0) zeros++;
    grader[v].push_back(s);
  }

  cout << zeros << endl;

  for(auto& a:grader)
  {
    if(a.first <= 0) break;
  }
  for(auto& a:grader)
  {
    if(a.first <= 0) break;
    vector<string> cop(a.second);
    sort(cop.begin(),cop.end(),[](string& a,string& b){
      return a > b;
    });
    for(auto& x:cop)
    {
      cout << a.first << " " << x << endl;
    }
  }

  return 0;
}
