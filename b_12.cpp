#include<bits/stdc++.h>
using namespace std;

int friend_count, relation_count;

vector<map<int,int>> matrix;


void solve(int current, map<int,int>& shouldExist)
{
  // TODO:FINISH ME
}

int main(){
  cin >> friend_count >> relation_count;

  matrix = vector<map<int,int>>(friend_count,map<int,int>());
  for(int i = 0;i<relation_count;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    matrix[a][b] = 1;
    matrix[b][a] = 1;
  }
  int max_friend = 0;

  for(int i=0;i<friend_count-1;i++)
  {
    // should exist stuff
  }
  cout << max_friend;

  return 0;
}


/*
 *
5 5
1 5
5 3
5 2
3 2
2 4
 */
