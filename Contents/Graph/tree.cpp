#include<bits/stdc++.h>
using namespace std;
#define M 100005
int tree[M] = {};  //parents
int r[M] = {};

struct Edge{
    int s, t, w;
    bool operator<(const Edge& r)const{
        return w < r.w;
    }
};

vector<Edge> G;

void init(int n){
    for(int i = 0; i <= n; i++){
        tree[i] = i;
        r[i] = 1;
    }
}
int Find(int n){
    if(tree[n] == n) return n;   //find root
    return tree[n] = Find(tree[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (r[a] <= r[b]){
        tree[a] = b;   //a接b 
        r[b]+=r[a];
    }
    else{
        tree[b] = a;  //b接a
        r[a] += r[b];
    }
}

int kruskal(){
    int cost = 0, flag = 0, Space = 0;
    for (auto it : G){
        it.s = Find(it.s);
        it.t = Find(it.t);
        if (it.s == it.t){
            if(Space) cout << ' ';
            Space = 1;
            flag = 1;
            cout << it.w;
            continue;
        }
        cost += it.w;
        Union(it.s, it.t);
    }
    return flag;
}
int main(){
    int point, side, Max = 0;
    while(cin >> point >> side){
        G.clear();
        if(point+side == 0) break;
        init(point);
        for(int i = 0; i < side; i++){
            Edge tmp;
            cin >> tmp.s >> tmp.t >> tmp.w;
            G.push_back(tmp);
        }
        sort(G.begin(), G.end());
        if(!kruskal()){
            cout << "forest";
        }
        cout << '\n';
    }
}