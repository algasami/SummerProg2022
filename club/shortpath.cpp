#include<bits/stdc++.h>
using namespace std;

unordered_map<char, set<pair<char,int>>> graph;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  while(true)
  {
    char a,b;
    int weight;
    cin >> a;
    if(a == '0') break;
    cin >> b >> weight;
    graph[a].insert(make_pair(b,weight));
    graph[b].insert(make_pair(a,weight));
  }

  cout << "---Graph Debug---" << endl;
  for(auto iter = graph.begin();iter!=graph.end();iter++)
  {
    cout << iter->first << ": ";
    for(auto& v:iter->second)
    {
      cout << v.first << "(" << v.second << ")";
    }
    cout << endl;
  }
  return 0;
}
