#include <bits/stdc++.h>
using namespace std;

vector<int> salary;

struct StaticVertex_T;
typedef const StaticVertex_T *const StaticVertex;

struct StaticVertex_T {
  const StaticVertex left, right;
  const int l, r, max, min;
  StaticVertex_T(StaticVertex left, StaticVertex right, int l, int r, int max,
                 int min)
      : l(l), r(r), max(max), min(min), left(left), right(right) {}
  ~StaticVertex_T() {
    if (left != nullptr)
      delete left;
    if (right != nullptr)
      delete right;
  }
  static StaticVertex construct(int l, int r) {
    if (l == r) {
      return new StaticVertex_T(nullptr, nullptr, l, r, salary[r], salary[r]);
    }
    int m = (l + r) / 2;
    StaticVertex leftNode = construct(l, m), rightNode = construct(m + 1, r);
    return new StaticVertex_T(leftNode, rightNode, l, r,
                              ::max({leftNode->max, rightNode->max}),
                              ::min({leftNode->min, rightNode->min}));
  }
  static int query(int l, int r, StaticVertex vertex, bool bQueryMax) {
    if (l == r)
      return salary[l];
    if (l == vertex->l && r == vertex->r) {
      return bQueryMax ? vertex->max : vertex->min;
    }
    int m = (vertex->r + vertex->l) / 2;
    if (r <= m) {
      if (vertex->left == nullptr)
        return -1;
      return query(l, r, vertex->left, bQueryMax);
    }
    if (l > m) {
      if (vertex->right == nullptr)
        return -1;
      return query(l, r, vertex->right, bQueryMax);
    }
    int lres = query(l, m, vertex->left, bQueryMax);
    int rres = query(m + 1, r, vertex->right, bQueryMax);
    return bQueryMax ? ::max({lres, rres}) : ::min({lres, rres});
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  int n;
  cin >> n >> q;
  salary.resize(n);

  for (size_t i = 0; i < n; i++) {
    cin >> salary[i];
  }

  StaticVertex vertex = StaticVertex_T::construct(0, n - 1);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int big(StaticVertex_T::query(a, b, vertex, true)),
        small(StaticVertex_T::query(a, b, vertex, false));
    cout << (big - small) << '\n';
  }

  delete vertex;
  return 0;
}
