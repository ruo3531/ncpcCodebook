#include<bits/stdc++.h>
using namespace std;
struct node{
    int l, r;
    node(){};
    node(int l, int r):l(l), r(r){};
    bool operator<(cnost node &a)const{
        return l < a.l;
    }
}

node gas[100005];
int main(){
    int L, G;
    while(cin >> L >> G){
        if(L == 0 && G == 0) break;
        for(int i = 0; i < G; i++){
            int a, b;
            cin >> a >> b;
            gas[i].l = a-b;
            gas[i].r = a+b;
        }
        sort(gas, gas+G);
        int ans = G, lcover = 0, rcover = 0,i = 0;
        while(L > lcover){
            rcover = lcover;
            for(; i < G && gas[i].l <= lcover; i++){
                if(gas[i].r > rcover) rcover = gas[i].r;
            } 
            if(lcover == rcover) break;
            lcover = rcover;
            ans--;
        }
        if(lcover < L) cout << "-1\n";
        else cout << ans << '\n';
    }
}
// 天然氣