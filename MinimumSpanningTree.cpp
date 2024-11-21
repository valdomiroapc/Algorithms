#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int f(int x, vector<int> &parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = f(parent[x], parent);
}

void u(int x, int y, vector<int> &parent, vector<int> &childsCount) {
    x = f(x, parent);
    y = f(y, parent);
    if (x == y) {
        return;
    }
    if (childsCount[x] > childsCount[y]) {
        parent[y] = x;
        childsCount[x] += childsCount[y];
    }
    else {
        parent[x] = y;
        childsCount[y] += childsCount[x];
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1), childsCount(n+1,1);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
    
    vector<pair<int, pair<int,int>>> e; 
    int x, y, k;
    for(int i=0; i<m; i++) {
        cin>>x>>y>>k;
        e.push_back(make_pair(k, make_pair(x,y)));
    }

    sort(e.begin(), e.end());

    int answer = 0;
    for(int i=0; i<e.size(); i++) {
        int w = e[i].first;
        int x = e[i].second.first;
        int y = e[i].second.second;
        if (f(x, parent) != f(y, parent)) {
            answer += w;
            u(x, y, parent, childsCount);
        }
    }
    cout<<answer<<endl;
}