#include <bits/stdc++.h>
using namespace std;


typedef set<int> intset;
struct node {
    intset adjs;
};
typedef vector<node> nvec;

ostream& operator<<(ostream& os, const intset& st)
{
    for(int i:st)
        os << i << ",";
    return os;
}

bool isSubset(const intset& sup, const intset& sub)
{
    for(int a:sub)
        if(sup.find(a) == sup.end()) return false;
    return true;
}

nvec pool;

int biggest = 0;
void bronKerbosch(int pivot, const intset& potential)
{
    //cout << pivot << endl;
    intset current{pivot};
    for(int n:potential)
    {
        if(current.find(n) == current.end() && isSubset(pool[n].adjs, current))
            current.insert(n);
    }
    //cout << current << endl;
    biggest = max({static_cast<int>(current.size()), biggest});
}


int main()
{
    int fcount, rcount;
    cin >> fcount >> rcount;
    pool = nvec(fcount, node());
    for(int i = 0;i < rcount;i++)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        pool[a].adjs.insert(b);
        pool[b].adjs.insert(a);
    }
    for(int i = 0;i < fcount;i++)
    {
        bronKerbosch(i, pool[i].adjs);
    }
    cout << biggest;
    return 0;
}
