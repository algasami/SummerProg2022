#include<bits/stdc++.h>
using namespace std;


vector<vector<double>> coordinate;

int m,n;
double solve_best = 0.0;

bool inside(int y, int x)
{
  return y < m && x << n && y >= 0 && x >= 0;
}

void solve(int y, int x, vector<vector<int>>& dead, double sum = 0.0)
{
  dead[y][x] = 1;
  sum += coordinate[y][x];
  if(x == n - 1)
  {
    if(sum > solve_best)
      solve_best = sum;
    return;
  }
  int ux = x, dx = x;
  int uy = y - 1, dy = y + 1;
  int rx = x + 1;
  int ry = y;

  double minVal = min({ inside(uy,ux) ? coordinate[uy][ux] : 999.0, inside(dy,dx) ? coordinate[dy][dx] : 999.0, inside(ry,rx) ? coordinate[ry][rx] : 999.0});
  if(inside(uy,ux) && coordinate[uy][ux] <= minVal) solve(uy,ux,dead,sum);
  if(inside(dy,dx) && coordinate[dy][dx] <= minVal) solve(dy,dx,dead,sum);
  if(inside(ry,rx) && coordinate[ry][rx] <= minVal) solve(ry,rx,dead,sum);
}

int main(){
  cin >> m >> n;
  coordinate = vector<vector<double>>(m,vector<double>(n,0.0));
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
      double n;
      cin >> n;
      coordinate[i][j] = n;
    }
  double min = -1.0;
  for(int y=0;y<m;y++)
    if(min < 0 || coordinate[y][0] < min)
      min = coordinate[y][0];

  for(int y=0;y<m;y++)
  {
    if(coordinate[y][0] <= min)
    {
      auto dead = vector<vector<int>>(m,vector<int>(n,0));
      solve(y, 0, dead);
    }
  }

  cout << std::fixed << std::setprecision(6) << solve_best;

  return 0;
}
