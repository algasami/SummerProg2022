/**
 * Input: A number. The number indicates the width of the chinese chess set (height is a constant 3)
 * Output:
 *  1. If there are no ways a horse can traverse through all the coordinates in the chinese chess set,
 *  output 0.
 *  2. Otherwise, output the order of the movement in lexicographical order.
 */

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

// Modified brute force
class vec{
public:
  int y,x;
  vec(int y,int x):y(y),x(x){}
};
typedef vector<vec> path;
typedef vector<vector<int>> map;

vector<path> results;
int n;

path copyPath(path& p) // Copies a path to dereference it
{
  path pa;
  for(auto& n:p)
    pa.push_back(vec(n.y,n.x));
  return pa;
}

void dfs(path p, vec next)
{
  if(next.y < 0 || next.x < 0 || next.y >= 3 || next.x >= n) return;
  for(auto& n:p) // Overlap
    if(n.y == next.y && n.x == next.x) return;
  p.push_back(next);
  if(p.size() >= 3*n)
  {
    results.push_back(p);
    return;
  }
  // explore
  int cy = next.y, cx = next.x;

  dfs(copyPath(p),vec(cy+1,cx+2));
  dfs(copyPath(p),vec(cy+2,cx+1));
  dfs(copyPath(p),vec(cy+1,cx-2));
  dfs(copyPath(p),vec(cy+2,cx-1));
  dfs(copyPath(p),vec(cy-1,cx-2));
  dfs(copyPath(p),vec(cy-2,cx-1));
  dfs(copyPath(p),vec(cy-1,cx+2));
  dfs(copyPath(p),vec(cy-2,cx+1));
}


// Will be transformed to 1d soon
vector<map> show;

void pathToMap(path& p) // Path to map coord
{
  map m = map(3,vector<int>(n,0));
  int j=0;
  for(auto& node:p)
    m[node.y][node.x] = ++j;
  show.push_back(m);
}

int main(){
  cin >> n;
  vec s(0,0);
  path p;
  dfs(p,s);
  for(auto& res:results)
    pathToMap(res);

  vector<int> elim = vector<int>(show.size(),0);
  if(elim.size() == 1)
  {
    for(int y = 0;y<3;y++)
    {
      for(int x=0;x<n;x++)
      {
        cout << show[0][y][x] << " ";
      }
    }
    return 0;
  }else if(elim.empty())
  {
    cout << "0";
    return 0;
  }
  int curans = 0;
  // Lexicographical Sorting
  for(int y = 0;y<3;y++)
  {
    for(int x=0;x<n;x++)
    {
      int index=-1;
      bool eq = false;
      for(auto& m:show)
      {
        index++;
        if(index == curans) continue;
        if(elim[index] != 0) continue;
        if(m[y][x] < show[curans][y][x])
        {
          curans = index;
          eq = false;
        }
        else if(m[y][x] == show[curans][y][x])
          eq = true;
        else
          elim[index] = 1;
      }
      if(eq == false)
      {
        for(int y = 0;y<3;y++)
        {
          for(int x=0;x<n;x++)
          {
            cout << show[curans][y][x] << " ";
          }
        }
        return 0;
      }
    }
  }
  return 0;
}

