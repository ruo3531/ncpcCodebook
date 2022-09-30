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
        // for(int i = 0; i < n; i++){
        //     cout << arr[i] << ":\n"[i == n-1];
        // }
        // for(int i = 0; i < n; i++){
        //     cout << dp[i] << ":\n"[i == n-1];
        // }
        // for(int i = 0; i < n; i++){
        //     cout << dp2[i] << ":\n"[i == n-1];
        // }
        int lds = 0, lis = 0;
        for(int i = 0; i < n; i++){
            Max = max(Max, min(dp[i],dp2[i]));
        }
        cout << 2*Max-1 << '\n';
    }

}