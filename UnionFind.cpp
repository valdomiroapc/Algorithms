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
    int n = 10; // number of nodes;
    vector<int> parent(n+1), childsCount(n+1,1);
    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }
}