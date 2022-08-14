#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
using namespace std;

class vec{
public:
  int y,x;
  vec(int y,int x):y(y),x(x){}
};

vec codemap[] = {
  vec(3,0),vec(3,1),vec(3,2),vec(3,3),
  vec(2,0),vec(2,1),vec(2,2),vec(2,3),
  vec(1,0),vec(1,1),vec(1,2),vec(1,3),
  vec(0,0),vec(0,1),vec(0,2),vec(0,3)
};

char vtc(vec& v) // Vector to Char
{
  for(int i=0;i<16;i++)
    if(codemap[i].y == v.y && codemap[i].x == v.x) return i + 'a';
  return '\0';
}

typedef vector<vec> path;
typedef vector<vector<int>> map;

vector<path> results;

path copyPath(path& p) // Copies a path to dereference it
{
  path pa;
  for(auto& n:p)
    pa.push_back(vec(n.y,n.x));
  return pa;
}

bool overlap(path& p,path& t) // If t is the subset of p
{
  int count = 0;
  for(auto& n1:p) for(auto& n2:t)
      if(n1.y == n2.y && n1.x == n2.x) count++;
  return count == t.size();
}

int gg = false; // Good game

// Add to queue
void grow(path& p,vec next,queue<path>& reach)
{
  path cp = copyPath(p);
  cp.push_back(next);
  reach.push(cp);
}
/**
 * Main Logic
 * 1. Input Path, Target, Queue (All Ref)
 * 2. Check valid:
 *    a. p's head
 *    b. overlapping itself ( explored )
 * 3. Check the result
 * 4. Grow -> send to queue
 */
void bfs(path& p, path& target,queue<path>& reach)
{
  vec& head = p[p.size()-1];
  if(head.y < 0 || head.x < 0 || head.y >= 4 || head.x >= 4) return;
  for(int i=0;i<p.size()-1;i++)
    if(head.y == p[i].y && head.x == p[i].x)return;
  if(overlap(p,target) == true){
    cout << (p.size() - 1) << endl;
    gg = true;
    return;
  }
  // explore ! Should've simplified the logic
  grow(p,vec(head.y+1,head.x),reach);
  grow(p,vec(head.y-1,head.x),reach);
  grow(p,vec(head.y,head.x+1),reach);
  grow(p,vec(head.y,head.x-1),reach);
}

int main(){
  int n;
  cin >> n;
  getchar(); // Prevent ghost characters
  vector<path> targets;
  for(int i=0;i<n;i++)
  {
    stringstream ss;
    string _r,b;
    getline(cin,_r);
    ss << _r;
    path t;
    while(ss >> b)
      t.push_back(codemap[b[0] - 'a']);
    targets.push_back(t);
  }
  for(int i=0;i<n;i++)
  {
    gg = false;
    queue<path> reach;
    path& targ = targets.at(i);
    path from;
    from.push_back(targ[0]);
    reach.push(from);
    do{
      path& p = reach.front();
      bfs(p,targ,reach);
      if(reach.empty() || gg) break;
      reach.pop();
    }while(reach.empty() == false);
  }
  return 0;
}

