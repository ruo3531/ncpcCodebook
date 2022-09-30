// uva12083
#include<bits/stdc++.h>
using namespace std;

const int M = 500+5;
struct people{
    int high;
    char sex;
    string music, sport; 
};

vector<int> G[M];
people Class[M];
int used[M] = {0};
int Last[M] = {0};

bool Check(people a, people b){
    if(abs(a.high-b.high) > 40) return true;
    if(a.sex == b.sex) return true;
    if(a.music != b.music) return true;
    if(a.sport == b.sport) return true;
    return false;
}

bool KM(int x){
    for(int i = 0; i < G[x].size(); i++){
        int v = G[x][i];
        if(used[v]) continue;
        used[v] = 1;
        if(Last[v] == -1 || KM(Last[v])){  //V找到還沒配對的人或前一個V配對的人找到別人
            Last[v] = x;
            return true;
        }
    }
    return false;
}

int Ans(int n){
    int Max = 0;
    memset(Last, -1, sizeof(Last));
    for(int i = 0; i < n; i++){
        memset(used, 0, sizeof(used));
        if(KM(i)){
            Max++;
        }
    }
    return Max;
}

int main(){
    int Cas;
    cin >> Cas;
    while(Cas--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            G[i].clear();
            cin >> Class[i].high >> Class[i].sex >> Class[i].music >> Class[i].sport;
        }
        for(int i = 0; i < n; i++){
            if(Class[i].sex == 'M') continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(!Check(Class[i], Class[j])){
                    G[i].push_back(j);
                }
            }
        }
        int MaxPeople = n-Ans(n);
        cout << MaxPeople << '\n';
    }

}