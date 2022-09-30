#include<bits/stdc++.h>
using namespace std;
#define M 10000
#define sq int(sqrt(double(M+5)));
bool prime[sq];
int main(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <sq; i++){
        if(prime[i]){
            for(int j = i*i; j < sq; j+=i){
                prime[j] = false;
            }
        }
    }
}