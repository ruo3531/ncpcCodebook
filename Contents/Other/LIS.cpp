#include<bits/stdc++.h>
using namespace std;
// 前後兩次LIS
int main(){
	int n;
    while(cin >> n){
        int arr[10005] = {0};
        int dp[10005] = {0};
        int dp2[10005] = {0};
        int Max = -1;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        for(int i = n-1; i >= 0; i--){
            dp2[i] = 1;
            for(int j = n-1; j > i; j--){
                if(arr[i] > arr[j]){
                    dp2[i] = max(dp2[i], dp2[j]+1);
                }
            }
        }
        int lds = 0, lis = 0;
        for(int i = 0; i < n; i++){
            Max = max(Max, min(dp[i],dp2[i]));
        }
        cout << 2*Max-1 << '\n';
    }

}

void LDS(vector<int> &s){
    if(s.size() == 0) return;
    vector<int> v;
    v.emplace_back(s[0]);
    revseq[0] = 1;
    for(int i = 1; i < s.size(); ++i){
        int n = s[i];
        if(n > v.back())
            v.push_back(n);
        else
            *lower_bound(v.begin(), v.end(), n) = n;
        revseq[i] = v.size();
    }
    return;
}