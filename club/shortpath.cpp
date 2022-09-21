#include<bits/stdc++.h>
using namespace std;

typedef set<pair<char,int>> edge;

unordered_map<char, edge> graph;
unordered_map<char, pair<set<string>, int>> solutions;

char start;

void dfs(string currentPath, int weight, const char nextNode, const char destination)
{
  if(currentPath.find(nextNode) != string::npos)
  {
    return;
  }
  currentPath += nextNode; // append path
  if(nextNode == destination)
  {
    // comparison between existing solutions and potential expansion
    // Bron Kerbosch variant
    if(solutions.find(destination) != solutions.end())
    {
      const pair<set<string>,int>& current = solutions[destination];
      if(current.second > weight)
      {
        solutions[destination].first.clear();
      } else if(current.second < weight)
      {
        return;
      }
    }
    solutions[destination].first.insert(currentPath);
    solutions[destination].second = weight;
    return;
  }
  // Collect edges (next, weight)
  for(auto& x:graph[nextNode])
  {
    dfs(currentPath, weight + x.second, x.first,destination);
  }
}

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
  cin >> start;
  for(auto iter = graph.begin();iter!=graph.end();iter++)
  {
    dfs("",0,start,iter->first);
  }

  for(auto iter = solutions.begin();iter!=solutions.end();iter++)
  {
    cout << start << "->" << iter->first << "'s shortest paths" << endl;
    cout << "Smallest weight: " << iter->second.second << endl;
    // cout << iter->first << "'s Solutions-------" << endl;
    // cout << start << "至" << iter->first << "的最短解法---" << endl;
    // cout << "最小權重: " << iter->second.second << endl;
    for(auto n:iter->second.first)
    {
      cout << n << endl;
    }
    cout << "-----------" << endl;
  }
  return 0;
}
