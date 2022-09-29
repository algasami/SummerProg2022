#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;

// Beautiful subgraphs!

// Halted..

vector<int> root;
vector<set<int>> adjs;

int const findRoot(int a) {
  if (root[a] == a)
    return a;
  return root[a] = findRoot(root[a]);
}

void makeUnion(int const a, int const b) { root[findRoot(b)] = findRoot(a); }

bool query(int const base, int const toFind) {
  return findRoot(base) == findRoot(toFind);
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  int edgecount, vertcount;
  cin >> vertcount >> edgecount;
  adjs.resize(vertcount);

  for (int i = 0; i < edgecount; i++) {
    int a, b;
    cin >> a >> b;
    adjs[a].insert(b);
    adjs[b].insert(a);
  }

  root.resize(vertcount);
  for (int i = 0; i < vertcount; i++) {
    bool beautiful = true;

    for (int j = 0; j <= i; j++) {
      root[j] = j;
    }
    for (int j = 0; j <= i; j++) {
      for (int n : adjs[j])
        if (n <= i)
          makeUnion(j, n);
    }
    for (int j = 0; j <= i; j++) {
      if (!query(0, j)) {
        beautiful = false;
        break;
      }
    }
    cout << (beautiful ? 1 : 0);
  }

  return 0;
}
