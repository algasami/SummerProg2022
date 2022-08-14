#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class coord {
public:
  int x,y,len;
  coord(int x = 0,int y = 0,int len = 0):x(x),y(y),len(len){}
};
int m,n,len=0;
vector<vector<int>> map;
queue<coord> que;
coord from,to;

// Input coordinate
istream& operator>>(istream& is,coord& co)
{
  is >> co.y >> co.x;
  co.x--;co.y--;
  co.len = 0;
  return is;
}

int inbound(coord& cd)
{
  return (cd.y < m && cd.x < n) && (cd.y >= 0 && cd .x >= 0);
}

void explore(coord c)
{
  que.push(c);
}
void bfs(coord& c)
{
  if(c.y == to.y && c.x == to.x){
    len = c.len;
    return;
  }
  if(inbound(c) == false || map[c.y][c.x] != 0) return;
  map[c.y][c.x] = -1;
  explore(coord(c.y+1,c.x,c.len + 1));
  explore(coord(c.y-1,c.x,c.len + 1));
  explore(coord(c.y,c.x+1,c.len + 1));
  explore(coord(c.y,c.x-1,c.len + 1));
}


int main(){
  cin >> m >> n;
  map = vector<vector<int>>(m,vector<int>());
  // Reading data
  for(int y=0;y<m;y++)
  {
    for(int x=0;x<n;x++)
    {
      char ch;cin >> ch;
      map[y].push_back(ch == '1' ? -1 : 0);
    }
  }
  cin >> from >> to;
  que.push(from);
  do{
    coord& n = que.front();
    bfs(n);
    if(que.empty() || len != 0)break;
    que.pop();
  }while(que.empty() == false);
  cout << len;
  return 0;
}

/*
8 8
11111111
10000001
10100101
10101001
10000101
11010001
10000101
11111111
6 7
4 4
*/
